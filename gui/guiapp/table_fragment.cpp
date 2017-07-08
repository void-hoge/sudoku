#include <QHeaderView>
#include "table_fragment.h"
#include "param.h"

using namespace std::string_literals;

table_fragment::table_fragment(QWidget *parent) : QTableWidget(parent) {
    if (auto* hh = horizontalHeader()) hh->setSectionResizeMode(QHeaderView::Stretch);
        else throw std::runtime_error("Couldn't get horizon header");
    if (auto* vh = verticalHeader()) vh->setSectionResizeMode(QHeaderView::Stretch);
        else throw std::runtime_error("Couldn't get vertical header");
    setColumnCount(eachside);
    setRowCount(eachside);
    for (auto i=0; i<all_cells_count; ++i) {
        setItem(cast_to_row(i), cast_to_col(i), new QTableWidgetItem(" "));
    }
}

QTableWidgetItem &table_fragment::operator[](size_t i) {
    return ref_to_item(cast_to_row(static_cast<int>(i)), cast_to_col(static_cast<int>(i)));
}

const QTableWidgetItem &table_fragment::operator[](size_t i) const {
    return ref_to_item_c(cast_to_row(static_cast<int>(i)), cast_to_col(static_cast<int>(i)));
}

QTableWidgetItem &table_fragment::ref_to_item(int abs) {
    return ref_to_item(cast_to_row(abs), cast_to_col(abs));
}

QTableWidgetItem &table_fragment::ref_to_item(int row, int col) {
    QTableWidgetItem* ptr = item(row, col);
    if (ptr == nullptr) throw std::out_of_range(
                std::to_string(row) + u8":"s + std::to_string(col) + u8" is out of range("s + std::to_string(all_cells_count) + u8")"s);
    return *ptr;
}

const QTableWidgetItem &table_fragment::ref_to_item_c(int row, int col) const {
    QTableWidgetItem* ptr = item(row, col);
    if (ptr == nullptr) throw std::out_of_range(
                std::to_string(row) + u8":"s + std::to_string(col) + u8" is out of range("s + std::to_string(all_cells_count) + u8")"s);
    return *ptr;
}

board_expression table_fragment::packaged_data() {
    board_expression ret;
    for (size_t i=0; i<all_cells_count; ++i) {
        auto text = operator[](i).text();
        ret[i] = text == " " ? -1 : text.toInt();
    }
    return ret;
}

void table_fragment::show(const board_expression &b) {
    for (size_t i=0; i<all_cells_count; ++i) {
        int num = b[i];
        operator[](i).setText(num == -1 ? " " : QString::number(num));
    }
}
