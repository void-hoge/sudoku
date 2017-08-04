#include "Board9.hpp"
#include <bitset>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

const uint81 minuint81 = 0;
const uint81 maxuint81 = ~minuint81;
const uint81 xMask = 0x1ff;
const uint81 constant = 0x40201;
const uint81 yMask = (constant << 54) | (constant << 27) | constant;
const uint81 constantBlock = 0x1c0e07;
const uint81 blockMask[9] = {	((constantBlock << 0) << 0),	((constantBlock << 3) << 0),	((constantBlock << 6) << 0),
								((constantBlock << 0) << 27),	((constantBlock << 3) << 27),	((constantBlock << 6) << 27),
								((constantBlock << 0) << 54),	((constantBlock << 3) << 54),	((constantBlock << 6) << 54)};

uint81 OR(uint81 *n){
	return n[0]|n[1]|n[2]|n[3]|n[4]|n[5]|n[6]|n[7]|n[8];
}

/**********************************public methods**********************************/


/*constructor*/
Board::Board(){
	for (int i = 0; i < 9; i++) {
		cells[i] = maxuint81;
		confirmedCells[i] = minuint81;
	}
}

void Board::input(){
	int n;

	for (int i = 0; i < 81; ++i){
		cin >> n;
		if (n == 0){
			continue;
		}
		set(i, n-1);
		setConfirmedCells(i, n-1);
	}
	return;
}

void Board::vectorInput(vector<int> v){
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			continue;
		}
		set(i, v[i]-1);
		setConfirmedCells(i, v[i]-1);
	}
	return;
}

void Board::output(){
	uint81 scanner = 1;

	for (int i = 0; i < 81; ++i){
		if (i % 9 == 0){
			cout << "|\n";
			if (i % 9 == 0){
				cout << "+--------+--------+--------+\n";
			}
		}

		if (i % 3 == 0){
			cout << "|" ;
		}	else{
			cout << ":";
		}

		for (int j = 0; j < 9; ++j){
			if ((confirmedCells[j] & scanner) != 0){
				cout << setw(2) << setfill(' ') << j+1;
				goto hoge;
			}
		}

		cout <<setw(2) << setfill(' ') << " ";
		hoge:;


		scanner <<= 1;
	}

	cout << "|\n+--------+--------+--------+\n" << endl;

}

int Board::check(int coordinate){
	for (int i = 0; i < 9; i++) {
		if (confirmedCells[i][coordinate]) {
			return i+1;
		}
	}
	return (-1);
}

void Board::put(int coordinate, int c){
	set(coordinate, c);
	setConfirmedCells(coordinate, c);
	return;
}

bool Board::update(){
	uint81 backup[9];
	memcpy(backup, confirmedCells, sizeof(uint81)*9);
	updateConfirmedCells();
	while ((OR(confirmedCells)&(~(OR(backup)))) != 0) {
		for (int i = 0; i < 9; i++) {
			uint81 addition = (confirmedCells[i] & (~(backup[i])));
			if (addition == 0) {
				continue;
			}
			for (int j = 0; j < 81; j++) {
				if (addition[j]) {
					set(j, i);
				}
			}
		}
		/*if there are some errors, return false.*/
		if (checkError()) {
			return false;
		}
		memcpy(backup, confirmedCells, sizeof(uint81)*9);
		updateConfirmedCells();
	}
	return true;
}

bitset<9> Board::setableNumber(int coordinate){
	bitset<9> r;
	for (int i = 0; i < 9; i++) {
		r[i] = cells[i][coordinate];
	}
	return r;
}

int Board::emptyCell(){
	uint81 n = OR(confirmedCells);
	for (int i = 0; i < 81; i++) {
		if (n[i] == false) {
			return i;
		}
	}
}

bool Board::isFinish(){
	return (~(OR(confirmedCells)) == 0);
}


/**********************************private methods**********************************/


void Board::set(int coordinate, int c){
	for (int i = 0; i < 9; ++i){
		cells[i][coordinate] = false;
	}

	uint81 mask = 0;
	int x = coordinate /9, y = coordinate %9, block;
	mask |= (xMask << (x*9));
	mask |= (yMask << y);
	block = (x/3)*3 + y/3;
	mask |= (blockMask[block]);

	cells[c] &= ~mask;
	cells[c][coordinate] = true;
	return;
}

void Board::updateConfirmedCells(){
	for (int i = 0; i < 9; ++i){
		confirmedCells[i] = cells[i];
		for (int j = 0; j < 9; ++j){
			if (i == j){
				continue;
			}
			confirmedCells[i] &= ~cells[j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			uint81 n = (cells[i] & (xMask << (j*9)));
			if (n.count() == 1) {
				confirmedCells[i] |= n;
			}

			n = (cells[i] & (yMask << j));
			if (n.count() == 1) {
				confirmedCells[i] |= n;
			}

			n = (cells[i] & blockMask[j]);
			if (n.count() == 1) {
				confirmedCells[i] |= n;
			}
		}
	}
	return;
}

void Board::setConfirmedCells(int coordinate, int c){
	confirmedCells[c][coordinate] = true;
	return;
}

bool Board::checkError(){
	/*When there is a cell that can't substitute any thing.*/
	return (~(OR(cells)) != 0);
}
