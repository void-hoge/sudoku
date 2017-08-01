#ifndef __SOLVER_HPP_INCLUDED__
#define __SOLVER_HPP_INCLUDED__

#include "../Board/Board.h"
#include <vector>

class Solver{
public:
	void input();
	void vectorInput(std::vector<int> v);
	void show();
	void solve();
	void testInput();
	int check(int);
	Board solution;
	Board q;
};

#endif
