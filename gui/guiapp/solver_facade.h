#ifndef SOLVER_FACADE_H
#define SOLVER_FACADE_H

#include "board_facade.h"
#include "16x16/Solver/Solver16.hpp"
#include "param.h"

class solver_facade {
        v16::Solver solver_m;

    public:
        v16::Solver low_solver() { return  solver_m; }

        solver_facade(v16::Solver& solver);
        solver_facade(v16::Solver&& solver = v16::Solver());

        BoardFacade solve(const board_expression& b);
        BoardFacade current_state() noexcept;
};

#endif // SOLVER_FACADE_H
