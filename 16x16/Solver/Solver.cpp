#include "Solver.h"
#include "../Board/Board.h"
#include <bitset>
using namespace std;

bool backtrack(Board q, int coordinate, int c){
	q.put(coordinate, c);

	if (!q.update()) {
		return false;
	}

	if (q.isFinish()) {
		q.output();
		return true;
	}

	coordinate = q.emptyCell();

	bitset<16> setable = q.setableNumber(coordinate);
	for (int i = 0; i < 16; i++) {
		if (setable[i] == 1) {
			if (backtrack(q, coordinate, i)) {
				return true;
			}
		}
	}
	return false;
}

void Solver::input(){
	q.input();
}

void Solver::show(){
	solution.output();
}

void Solver::solve(){
	if (!q.update()) {
		return;
	}

	if (q.isFinish()) {
		solution = q;
		return;
	}

	int coordinate = q.emptyCell();
	bitset<16> setable = q.setableNumber(coordinate);
	for (int i = 0; i < 16; i++) {
		if (setable[i] == 1) {
			if (backtrack(q, coordinate, i)) {
				return;
			}
		}
	}
	return;
}
