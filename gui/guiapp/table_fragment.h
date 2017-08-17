#ifndef TABLE_FRAGMENT_H
#define TABLE_FRAGMENT_H

#include <QTableWidget>
#include "utils.h"
#include "board.h"

class table_fragment : public QTableWidget {
    Q_OBJECT
    int size;
public:
    explicit table_fragment(QWidget *parent = nullptr);

    template <class TYPE>
    void notice() {
        size = TYPE::size;
        setColumnCount(size);
        setRowCount(size);
        // Set items
        for (auto i=0; i<cells_count<TYPE>; ++i) {
            auto p = point<TYPE>{i};
            setItem(p.row(), p.col(), new QTableWidgetItem(" "));
        }
    }

    template <class TYPE>
    QTableWidgetItem& at(const point<TYPE>& p) {
        if (TYPE::size != size) throw std::logic_error("Passed invalid size type.");
        auto* ptr = item(p.row(), p.col());
        if (ptr == nullptr) throw std::invalid_argument("Arg points invalid position. Fetched nullptr.");
        return *ptr;
    }

    template <class TYPE>
    board<TYPE> data();

    // set compiled data
    template <class TYPE>
    void set_data(board<TYPE>& b);

    template <class TYPE>
    void set_data(board<TYPE>&& b);

signals:

public slots:
};

#endif // TABLE_FRAGMENT_H
