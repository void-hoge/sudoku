#include "Solver9.hpp"
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

	bitset<9> setable = p.setableNumber(coordinate);
	for (int i = 0; i < 9; i++) {
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
	bitset<9> setable = p.setableNumber(coordinate);
	for (int i = 0; i < 9; i++) {
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
	for (int i = 0; i < 81; ++i){
		if ((i % 9) == 0){
			cout << endl;
		}
		cout << check(i) << " ";
	}
}

void Solver::testInput(){
	vector<int> v{	5, 3, 0, 0, 7, 0, 0, 0, 0,
				6, 0, 0, 1, 9, 5, 0, 0, 0,
				0, 9, 8, 0, 0, 0, 0, 6, 0,
				8, 0, 0, 0, 6, 0, 0, 0, 3,
				4, 0, 0, 8, 0, 3, 0, 0, 1,
				7, 0, 0, 0, 2, 0, 0, 0, 6,
				0, 6, 0, 0, 0, 0, 2, 8, 0,
				0, 0, 0, 4, 1, 9, 0, 0, 5,
				0, 0, 0, 0, 8, 0, 0, 7, 9};
	vectorInput(v);
	return;
}
