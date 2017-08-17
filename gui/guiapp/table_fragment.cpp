#include <QHeaderView>
#include "table_fragment.h"
#include "param.h"

using namespace std::string_literals;

table_fragment::table_fragment(QWidget *parent) : QTableWidget(parent) {
    // Resize automatically adjusting to window.
    if (auto* hh = horizontalHeader()) hh->setSectionResizeMode(QHeaderView::Stretch);
        else throw std::runtime_error("Couldn't get horizon header");
    if (auto* vh = verticalHeader()) vh->setSectionResizeMode(QHeaderView::Stretch);
    else throw std::runtime_error("Couldn't get vertical header");
}

template<>
board<V9_FLAG> table_fragment::data() {
    if (V9_FLAG::size != size) std::logic_error("Tmp param TYPE is not compatible with current table size.");
    board<V9_FLAG> b;
    for (int i=0; i<size*size; ++i) {
        auto&& p = point<V9_FLAG>{i};
        auto&& text = at(p).text();
        b.set(p, text == " " ? 0 : text.toInt());
    }
    return b;
}

template <>
board<V16_FLAG> table_fragment::data() {
    if (V16_FLAG::size != size) std::logic_error("Tmp param TYPE is not compatible with current table size.");
    board<V16_FLAG> b;
    for (int i=0; i<size*size; ++i) {
        auto&& p = point<V16_FLAG>{i};
        auto&& text = at(p).text();
        b.set(p, text == " " ? 0 : text.toInt());
    }
    return b;
}

template <>
void table_fragment::set_data(board<V9_FLAG>& b) {
    for (int i=0; i<size*size; ++i) {
        auto&& p = point<V9_FLAG>{i};
        auto&& num = b.at(p);
        at(p).setText(num == 0 ? " " : QString::number(num));
    }
}

template <>
void table_fragment::set_data(board<V16_FLAG>& b) {
    for (int i=0; i<size*size; ++i) {
        auto&& p = point<V16_FLAG>{i};
        auto&& num = b.at(p);
        at(p).setText(num == 0 ? " " : QString::number(num));
    }
}

template <>
void table_fragment::set_data(board<V9_FLAG>&& b) {
    for (int i=0; i<size*size; ++i) {
        auto&& p = point<V9_FLAG>{i};
        auto&& num = b.at(p);
        at(p).setText(num == 0 ? " " : QString::number(num));
    }
}

template <>
void table_fragment::set_data(board<V16_FLAG>&& b) {
    for (int i=0; i<size*size; ++i) {
        auto&& p = point<V16_FLAG>{i};
        auto&& num = b.at(p);
        at(p).setText(num == 0 ? " " : QString::number(num));
    }
}
