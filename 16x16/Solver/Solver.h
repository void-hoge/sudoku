#ifndef __SOLVER_HPP_INCLUDED__
#define __SOLVER_HPP_INCLUDED__

#include "../Board/Board.h"
using namespace std;

class Solver{
public:
	void input();
	void show();
	void solve();
	Board solution;
private:
	Board q;
};

#endif
