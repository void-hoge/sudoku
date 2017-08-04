#ifndef __SOLVER_HPP_INCLUDED__
#define __SOLVER_HPP_INCLUDED__

#include "../Board/Board9.hpp"
#include <vector>

namespace v9 {
    class Solver{
    public:
        void input();
        void vectorInput(std::vector<int> v);
        void show();
        void checkShow();
        void solve();
        void testInput();
        int check(int);
        Board q;
    };
}

#endif
