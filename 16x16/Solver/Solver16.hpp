#ifndef __SOLVER_V16_INCLUDED__
#define __SOLVER_V16_INCLUDED__

#include "../Board/Board16.hpp"
#include <vector>

namespace v16 {
    class Solver{
    public:
        void input();
        void vectorInput(std::vector<int> v);
        void show();
        void checkShow();
        void solve();
        void testInput();
        int check(int);
        b16::Board q;
    };
}

#endif
