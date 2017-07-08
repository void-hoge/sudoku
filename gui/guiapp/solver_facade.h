#ifndef SOLVER_FACADE_H
#define SOLVER_FACADE_H

#include "../../16x16/Solver/Solver.h"
#include "board_facade.h"
#include "param.h"

class solver_facade {
        Solver solver_m;

    public:
        solver_facade(Solver& solver);
        solver_facade(Solver&& solver = Solver());

        BoardFacade solve();
        BoardFacade current_state() noexcept;
};

#endif // SOLVER_FACADE_H
