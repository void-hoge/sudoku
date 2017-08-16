//g++ main.cpp 16x16/Solver/Solver16.cpp 16x16/Board/Board16.cpp 9x9/Solver/Solver16.cpp 9x9/Board/Board16.cpp
#include "16x16/Solver/Solver16.hpp"
#include "9x9/Solver/Solver16.hpp"

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
