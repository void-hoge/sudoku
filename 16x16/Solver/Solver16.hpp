#ifndef __SOLVER_HPP_INCLUDED__
#define __SOLVER_HPP_INCLUDED__

#include "../Board/Board16.hpp"
#include <vector>

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

#endif
