#include "Solver/Solver16.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
	Solver poyo;
	poyo.testInput();
	poyo.show();
	poyo.solve();
	poyo.show();
	return 0;
}
