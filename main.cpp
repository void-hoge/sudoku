//g++ main.cpp 16x16/Solver/Solver.cpp 16x16/Board/Board.cpp 9x9/Solver/Solver.cpp 9x9/Board/Board.cpp
#include "16x16/Solver/Solver.hpp"
#include "9x9/Solver/Solver.hpp"

int main(int argc, char const *argv[]) {
	v9::Solver nine;
	v16::Solver sixteen;
	nine.testInput();
	nine.solve();
	nine.show();
	sixteen.testInput();
	sixteen.solve();
	sixteen.show();
	return 0;
}
