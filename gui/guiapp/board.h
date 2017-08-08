#ifndef BOARD_H
#define BOARD_H

#include "point.h"
#include "16x16/Board/Board16.hpp"
#include "9x9/Board/Board9.hpp"

template <class TYPE>
class board {
        using low_board_type = typename V16_V9_Switcher<v16::Board, v9::Board>::SwitchBy<TYPE>::type;
        low_board_type board_m;
    public:
        board(const low_board_type& init): board_m{init} {}

        int at(const point<TYPE>& p) {
            return board_m.check(p.abs());
        }

        template <class T>
        std::vector<int> data() {
            std::vector<int> ret{};
            for (int i=0; i<cells_count<TYPE>; ++i) {
                ret.push_back(at(point<TYPE>{i}));
            }
        }

        void set(const point<TYPE>& p, int data) {
            board_m.put(p.abs(), data);
        }

        template <class T>
        void set(const T& data) {
            for (int i=0; i<=cells_count<TYPE>; ++i) {
                set(point<TYPE>{i}, data.at(i));
            }
        }
};

#endif // BOARD_H
