#include "solver_facade.h"

solver_facade::solver_facade(Solver& solver): solver_m{solver} {

}

solver_facade::solver_facade(Solver&& solver): solver_m{solver} {

}

BoardFacade solver_facade::result() {
    return BoardFacade(solver_m.solution);
}

void solver_facade::solve() {
    solver_m.solve();
}
