#include "solver_facade.h"

solver_facade::solver_facade(Solver& solver): solver_m{solver} {

}

solver_facade::solver_facade(Solver&& solver): solver_m{solver} {

}

BoardFacade solver_facade::solve() {
    solver_m.solve();
    return solver_m.solution;
}

BoardFacade solver_facade::current_state() noexcept {
    return BoardFacade(solver_m.solution);
}
