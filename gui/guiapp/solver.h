#ifndef SOLVER_H
#define SOLVER_H

#include "utils.h"
#include "board.h"
#include "16x16/Solver/Solver16.hpp"
#include "9x9/Solver/Solver9.hpp"

template <class TYPE>
class solver {
        using low_solver_type = typename V16_V9_Switcher<v16::Solver, v9::Solver>::SwitchBy<TYPE>::type;
        low_solver_type solver_m;
    public:
        void solve() {
            solver_m.solve();
        }

        void set_data(const board<TYPE>& b) {
            solver_m.vectorInput(b.data());
        }

        board<TYPE> content() {
            return board<TYPE>{ solver_m.q };
        }

        void test_input() {
            solver_m.testInput();
        }
};

#endif // SOLVER_H
