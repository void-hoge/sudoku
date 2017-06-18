#include "Board.h"
#include <iostream>
#include <bitset>
using namespace std;

int node = 0;

bool backtrack(Board q, int coordinate, int c){
	node++;
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

void solve(Board q){
	q.input();
	q.output();
	q.update();
	if (!q.update()) {
		return;
	}

	if (q.isFinish()) {
		q.output();
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

int main(int argc, char const *argv[]) {
	Board q;
	solve(q);
	cout << "node: " << node << endl;
	return 0;
}
