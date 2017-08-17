#ifndef POINT_H
#define POINT_H

// this class represents a point on table.
// can use to target a cell on the QTableWidget.

#include <string>
#include <stdexcept>
#include "utils.h"

template <class TYPE>
class point final {
        int abs_pos_m;
    public:
        point(int abs): abs_pos_m{abs} {
            if (abs_pos() < 0 || cells_count<TYPE> <= abs_pos())
                throw std::invalid_argument{
                    "abs is out of range(0~" + std::to_string(cells_count<TYPE>-1) + ") <-act " + std::to_string(abs)};
        }
        point(int r, int c): abs_pos_m{r + c*TYPE::size} {
            std::string msg;
            const bool br = row() < 0 || size<TYPE> <= row();
            const bool bc = col() < 0 || size<TYPE> <= col();
            if (br || bc) {
                if (br) msg = "row is out of range(0~" + std::to_string(size<TYPE>) + ")";
                if (bc) msg = "col is out of range(0~" + std::to_string(size<TYPE>) + ")";
                throw std::invalid_argument(msg);
            }
        }
        int abs_pos() const noexcept {
            return abs_pos_m;
        }
        int row() const noexcept {
            return abs_pos_m / size<TYPE>;
        }
        int col() const noexcept {
            return abs_pos_m % size<TYPE>;
        }
};

#endif // POINT_H
