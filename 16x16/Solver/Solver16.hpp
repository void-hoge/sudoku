#ifndef SOLVER16_HPP_INCLUDED
#define SOLVER16_HPP_INCLUDED

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
        Board q;
    };
}

#endif
