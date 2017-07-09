#ifndef __SOLVER_HPP_INCLUDED__
#define __SOLVER_HPP_INCLUDED__

#include "../Board/Board.h"
#include <vector>
using namespace std;

class Solver{
public:
	void input();
	void vectorInput(vector<int> v);
	void show();
	void solve();
	void testInput();
	Board solution;
private:
	Board q;
};

#endif
