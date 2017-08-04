#ifndef SOLVER_FACADE_H
#define SOLVER_FACADE_H

#include "board_facade.h"
#include "16x16/Solver/Solver16.hpp"
#include "param.h"

class solver_facade {
        Solver solver_m;

    public:
        Solver low_solver() { return  solver_m; }

        solver_facade(Solver& solver);
        solver_facade(Solver&& solver = Solver());

        BoardFacade solve(const board_expression& b);
        BoardFacade current_state() noexcept;
};

#endif // SOLVER_FACADE_H
