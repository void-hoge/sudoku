#include "Board.h"
#include <bitset>
#include <string.h>
#include <iostream>
using namespace std;
#define base bitset<256>

const base minBase = 0;
const base maxBase = ~minBase;
const base xMask = 0x000000000000ffff;
const base constant = 0x0001000100010001;
const base yMask = (constant << 192) | (constant << 128) | (constant << 64) | constant;
const base constantBlock = 0x000f000f000f000f;
const base blockMask[16] = {	((constantBlock << 0) << 0),	((constantBlock << 4) << 0),	((constantBlock << 8) << 0),	((constantBlock << 12) << 0),
								((constantBlock << 0) << 64),	((constantBlock << 4) << 64),	((constantBlock << 8) << 64),	((constantBlock << 12) << 64),
								((constantBlock << 0) << 128),	((constantBlock << 4) << 128),	((constantBlock << 8) << 128),	((constantBlock << 12) << 128),
								((constantBlock << 0) << 192),	((constantBlock << 4) << 192),	((constantBlock << 8) << 192),	((constantBlock << 12) << 192)};

base OR(base *n){
	return n[0]|n[1]|n[2]|n[3]|n[4]|n[5]|n[6]|n[7]|n[8]|n[9]|n[10]|n[11]|n[12]|n[13]|n[14]|n[15];
}

bool Board::update(){
	base backup[16];
	memcpy(backup, confirmedCells, sizeof(base)*16);
	updateConfirmedCells();
	while ((OR(confirmedCells)&(~(OR(backup)))) != 0) {
		for (int i = 0; i < 16; i++) {
			base addition = (confirmedCells[i] & (~(backup[i])));
			if (addition == 0) {
				continue;
			}
			for (int j = 0; j < 256; j++) {
				if (addition[j]) {
					set(j, i);
				}
			}
		}
		if (checkError()) {
			return false;
		}
		memcpy(backup, confirmedCells, sizeof(base)*16);
		updateConfirmedCells();
	}
	return true;
}

bool Board::isFinish(){
	return (~(OR(confirmedCells)) == 0);
}

/*Returns true if there is an error.*/
bool Board::checkError(){
	/*When there is a cell that can't substitute any thing.*/
	return (~(OR(cells)) != 0);
}

bitset<16> Board::setableNumber(int coordinate){
	bitset<16> r;
	for (int i = 0; i < 16; i++) {
		r[i] = cells[i][coordinate];
	}
	return r;
}

int Board::emptyCell(){
	base n = OR(confirmedCells);
	for (int i = 0; i < 256; i++) {
		if (n[i] == false) {
			return i;
		}
	}
}

void binary(base n){
	for (int i = 0; i < 256; i++) {
		if ((i % 16) == 0) cout << endl;
		cout << n[i];
	}
	cout << endl;
}

void Board::debug(){
	// for (int i = 0; i < 16; i++) {
	// 	cout << "**" << i << "**" << endl;
	// 	binary(cells[i]);
	// 	cout << endl;
	// }
	binary(OR(cells));
	return;
}
