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

        QTableWidgetItem& operator[](size_t i);
        const QTableWidgetItem& operator[](size_t i) const;

        QTableWidgetItem& ref_to_item(int abs);
        QTableWidgetItem& ref_to_item(int row, int col);
        const QTableWidgetItem& ref_to_item_c(int row, int col) const;

        board_expression packaged_data();
        void show(const board_expression& b);

    signals:

    public slots:
};

#endif // TABLE_FRAGMENT_H
