#include "solver_facade.h"

solver_facade::solver_facade(Solver& solver): solver_m{solver} {

}

solver_facade::solver_facade(Solver&& solver): solver_m{solver} {

}

BoardFacade solver_facade::solve(const board_expression& b) {
    std::vector<int> v;
    for (auto& i : b) {
        v.push_back(i);
    }
    solver_m.vectorInput(v);
    solver_m.solve();
    return solver_m.q;
}

BoardFacade solver_facade::current_state() noexcept {
    return BoardFacade(solver_m.q);
}
