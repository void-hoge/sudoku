#include "Solver.hpp"
#include "../Board/Board.hpp"
#include <bitset>
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

bool backtrack(Board p, int coordinate, int c, Board* q){

	p.put(coordinate, c);

	if (p.isFinish()) {
		*q = p;
		return true;
	}

	bitset<16> setable = p.setableNumber(coordinate);
	for (int i = 0; i < 16; i++) {
		if (setable[i] == 1) {
			if (backtrack(p, coordinate, i, q)) {
				return true;
			}
		}
	}
	return false;
}

void Solver::input(){
	q.input();
}

void Solver::vectorInput(vector<int> v){
	q.vectorInput(v);
}

void Solver::show(){
	q.output();
}

void Solver::solve(){
	Board p = q;

	if (!p.update()) {
		return;
	}

	if (p.isFinish()) {
		q = p;
		return;
	}

	int coordinate = p.emptyCell();
	bitset<16> setable = p.setableNumber(coordinate);
	for (int i = 0; i < 16; i++) {
		if (setable[i] == 1) {
			if (backtrack(p, coordinate, i, &q)) {
				return;
			}
		}
	}
	throw runtime_error("This sudoku can't be solved.");
	return;
}

int Solver::check(int coordinate) {
	return q.check(coordinate);
}

void Solver::checkShow(){
	for (int i = 0; i < 256; ++i){
		if ((i % 16) == 0){
			cout << endl;
		}
		cout << check(i) << " ";
	}
}

void Solver::testInput(){
	vector<int> v{1, 0, 2, 0, 	0, 14, 5, 13, 	0, 10, 0, 0, 	0, 11, 0, 0,
	0, 0, 16, 0, 	0, 0, 0, 7, 	0, 11, 14, 6, 	0, 0, 13, 10,
	15, 11, 0, 0, 	0, 6, 0, 1, 	2, 0, 0, 0, 	8, 0, 0, 12,
	6, 0, 0, 12, 	0, 0, 0, 8, 	4, 0, 7, 9, 	0, 0, 0, 3,

	0, 0, 0, 9, 	2, 1, 0, 0, 	12, 14, 0, 0, 	7, 6, 0, 0,
	5, 13, 1, 0, 	0, 0, 16, 6, 	0, 3, 15, 4, 	0, 8, 0, 11,
	10, 2, 0, 0, 	13, 5, 3, 0, 	0, 0, 0, 7, 	0, 15, 16, 0,
	0, 0, 15, 0, 	14, 0, 4, 11, 	0, 1, 6, 2, 	10, 0, 0, 0,

	16, 10, 0, 0, 	8, 7, 0, 0, 	0, 12, 0, 0, 	0, 0, 0, 0,
	0, 0, 0, 0, 	12, 0, 14, 0, 	13, 0, 16, 0, 	0, 0, 5, 0,
	0, 7, 6, 11, 	0, 15, 2, 0,	0, 0, 8, 0, 	4, 0, 0, 0,
	3, 15, 0, 4, 	11, 13, 0, 0, 	5, 0, 0, 0, 	9, 1, 0, 0,

	0, 1, 0, 2, 	0, 11, 0, 4, 	0, 0, 10, 0, 	0, 5, 14, 16,
	0, 0, 10, 0, 	1, 12, 0, 0, 	14, 13, 0, 16, 	0, 7, 6, 0,
	0, 0, 14, 0, 	0, 0, 7, 10, 	9, 0, 0, 15, 	1, 0, 0, 0,
	0, 6, 0, 8, 	0, 0, 13, 0, 	0, 4, 0, 3, 	2, 0, 0, 15};
	vectorInput(v);
	return;
}
