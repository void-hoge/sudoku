#include "solver_facade.h"

solver_facade::solver_facade(Solver& solver): solver_m{solver} {

}

solver_facade::solver_facade(Solver&& solver): solver_m{solver} {

}

board_expression solver_facade::solve(const board_expression& b) {
    std::vector<int> v;
    for (auto& i : b) {
        v.push_back(i);
    }
    solver_m.vectorInput(v);
    solver_m.solve();
    return compile(solver_m.solution);
}

board_expression solver_facade::current_state() noexcept {
    return compile(solver_m.solution);
}

board_expression solver_facade::test_input() {
    solver_m.testInput();
    return compile(solver_m.q);
}
