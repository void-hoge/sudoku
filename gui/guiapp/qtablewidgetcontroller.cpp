#include "qtablewidgetcontroller.h"

QTableWidgetItemAdapter::QTableWidgetItemAdapter(QTableWidget& to_be_adaptered): table{to_be_adaptered} {

}

QTableWidgetItemAdapter::QTableWidgetItemIterator QTableWidgetItemAdapter::begin() const noexcept {
    return QTableWidgetItemIterator(table, 0);
}

QTableWidgetItemAdapter::QTableWidgetItemIterator QTableWidgetItemAdapter::end() const noexcept {
    return QTableWidgetItemIterator(table, all_cells_count-1);
}

QTableWidgetItemAdapter::QTableWidgetItemIterator::QTableWidgetItemIterator(const QTableWidget& ref_to, int point)
    : low_point{point}, table{ref_to} { }
