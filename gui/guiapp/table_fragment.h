#ifndef TABLE_FRAGMENT_H
#define TABLE_FRAGMENT_H

#include <QTableWidget>
#include "param.h"

class table_fragment : public QTableWidget {
        Q_OBJECT
    public:
        static inline int cast_to_row(int i) noexcept{ return i%eachside; }
        static inline int cast_to_col(int i) noexcept { return i/eachside; }
        static inline int cast_to_abs(int row, int col) noexcept { return row*eachside+col; }

        explicit table_fragment(QWidget *parent = nullptr);

        // access to available items in the table.
        // throws std::out_of_range passing point of uninitialized item.
        QTableWidgetItem& operator[](size_t i);
        const QTableWidgetItem& operator[](size_t i) const;

        // Same as operator[]
        QTableWidgetItem& ref_to_item(int abs);
        QTableWidgetItem& ref_to_item(int row, int col);
        const QTableWidgetItem& ref_to_item_c(int row, int col) const;

        // compile item data as std::array<size, int>
        board_expression packaged_data();

        // set compiled data
        void set_data(const board_expression& b);

    signals:

    public slots:
};

#endif // TABLE_FRAGMENT_H
