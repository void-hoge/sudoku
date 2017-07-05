#include "Solver/Solver.h"
using namespace std;

int main(int argc, char const *argv[]) {
	Solver poyo;
	poyo.input();
	poyo.solve();
	poyo.show();
	return 0;
}
