#ifndef QTABLEWIDGETCONTROLLER_H
#define QTABLEWIDGETCONTROLLER_H

#include <iterator>
#include <QTableWidgetItem>
#include <param.h>

class QTableWidgetItemAdapter {
        const QTableWidget& table;
    public:
        static inline int cast_to_row(int through_index) { return through_index/eachside; }
        static inline int cast_to_column(int through_index) { return through_index%eachside; }

        class QTableWidgetItemIterator: private std::iterator<std::input_iterator_tag, QTableWidgetItem> {
                int low_point;
                const QTableWidget& table;

            public:
                QTableWidgetItemIterator(const QTableWidget& ref_to, int point);
                inline QTableWidgetItemIterator& operator++ () noexcept {
                    low_point++;
                    return *this;
                }
                inline QTableWidgetItem& operator *() noexcept {
                    auto* ret = table.itemAt(cast_to_row(low_point), cast_to_column(low_point));
                    if (ret == nullptr) ret = new QTableWidgetItem(QString("Uninitialized"));
                    return *ret;
                }
                inline int abs_index() noexcept {
                    return low_point;
                }
        };
        QTableWidgetItemAdapter(QTableWidget& to_be_adaptered);
        QTableWidgetItemIterator begin() const noexcept;
        QTableWidgetItemIterator end() const noexcept;
        QTableWidgetItemIterator itemAt(int row, int column) const noexcept;
};

#endif // QTABLEWIDGETCONTROLLER_H
