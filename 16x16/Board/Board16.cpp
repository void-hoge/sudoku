#include "Board16.hpp"
#include <vector>
#include <bitset>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

const uint256 minuint256 = 0;
const uint256 maxuint256 = ~minuint256;
const uint256 xMask = 0x000000000000ffff;
const uint256 constant = 0x0001000100010001;
const uint256 yMask = (constant << 192) | (constant << 128) | (constant << 64) | constant;
const uint256 constantBlock = 0x000f000f000f000f;
const uint256 blockMask[16] = {	((constantBlock << 0) << 0),	((constantBlock << 4) << 0),	((constantBlock << 8) << 0),	((constantBlock << 12) << 0),
								((constantBlock << 0) << 64),	((constantBlock << 4) << 64),	((constantBlock << 8) << 64),	((constantBlock << 12) << 64),
								((constantBlock << 0) << 128),	((constantBlock << 4) << 128),	((constantBlock << 8) << 128),	((constantBlock << 12) << 128),
								((constantBlock << 0) << 192),	((constantBlock << 4) << 192),	((constantBlock << 8) << 192),	((constantBlock << 12) << 192)};

uint256 OR(uint256 *n){
	return n[0]|n[1]|n[2]|n[3]|n[4]|n[5]|n[6]|n[7]|n[8]|n[9]|n[10]|n[11]|n[12]|n[13]|n[14]|n[15];
}

namespace b16 {

/**********************************public methods**********************************/


/*constructor*/
Board::Board(){
	for (int i = 0; i < 16; i++) {
		cells[i] = maxuint256;
		confirmedCells[i] = minuint256;
	}
}

void Board::input(){
	int n;

	for (int i = 0; i < 256; ++i){
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
		if(v[i] == 0){
			continue;
		}
		set(i, v[i]-1);
		setConfirmedCells(i, v[i]-1);
	}
	return;
}

void Board::output(){
	uint256 scanner = 1;

	for (int i = 0; i < 256; ++i){
		if (i % 16 == 0){
			cout << "|\n";
			if (i % 64 == 0){
				cout << "+-------+-------+-------+-------+-------+-------+-------+-------+\n";
			}
		}

		if (i % 4 == 0){
			cout << "|" ;
		}	else{
			cout << ":";
		}

		for (int j = 0; j < 16; ++j){
			if ((confirmedCells[j] & scanner) != 0){
				cout << setw(3) << setfill(' ') << j+1;
				goto hoge;
			}
		}

		cout <<setw(3) << setfill(' ') << " ";
		hoge:;


		scanner <<= 1;
	}

	cout << "|\n+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
}

int Board::check(int coordinate){
	for (int i = 0; i < 16; i++) {
		if (confirmedCells[i][coordinate]) {
			return i+1;
		}
	}
	return 0;
}

void Board::put(int coordinate, int c){
	set(coordinate, c);
	setConfirmedCells(coordinate, c);
	return;
}

bool Board::update(){
	uint256 backup[16];
	memcpy(backup, confirmedCells, sizeof(uint256)*16);
	updateConfirmedCells();
	while ((OR(confirmedCells)&(~(OR(backup)))) != 0) {
		for (int i = 0; i < 16; i++) {
			uint256 addition = (confirmedCells[i] & (~(backup[i])));
			if (addition == 0) {
				continue;
			}
			for (int j = 0; j < 256; j++) {
				if (addition[j]) {
					set(j, i);
				}
			}
		}
		/*if there are some errors, return false.*/
		if (checkError()) {
			return false;
		}
		memcpy(backup, confirmedCells, sizeof(uint256)*16);
		updateConfirmedCells();
	}
	return true;
}

bitset<16> Board::setableNumber(int coordinate){
	bitset<16> r;
	for (int i = 0; i < 16; i++) {
		r[i] = cells[i][coordinate];
	}
	return r;
}

int Board::emptyCell(){
	uint256 n = OR(confirmedCells);
	for (int i = 0; i < 256; i++) {
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
	for (int i = 0; i < 16; ++i){
		cells[i][coordinate] = false;
	}

	uint256 mask = 0;
	int x = coordinate /16, y = coordinate %16, block;
	mask |= (xMask << (x*16));
	mask |= (yMask << y);
	block = (x/4)*4 + y/4;
	mask |= (blockMask[block]);

	cells[c] &= ~mask;
	cells[c][coordinate] = true;
	return;
}

void Board::updateConfirmedCells(){
	for (int i = 0; i < 16; ++i){
		confirmedCells[i] = cells[i];
		for (int j = 0; j < 16; ++j){
			if (i == j){
				continue;
			}
			confirmedCells[i] &= ~cells[j];
		}
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			uint256 n = (cells[i] & (xMask << (j*16)));
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

}
