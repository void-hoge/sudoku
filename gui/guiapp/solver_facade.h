#ifndef SOLVER_FACADE_H
#define SOLVER_FACADE_H

#include "../../16x16/Solver/Solver.h"
#include "board_util.h"
#include "param.h"

class solver_facade {
        Solver solver_m;

    public:
        Solver low_solver() { return  solver_m; }

        solver_facade(Solver& solver);
        solver_facade(Solver&& solver = Solver());

        board_expression solve(const board_expression& b);
        board_expression current_state() noexcept;
        board_expression test_input();
};

#endif // SOLVER_FACADE_H
