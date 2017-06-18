#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <bitset>
using namespace std;

#define base bitset<256>

class Board{
public:
	Board();
	void input();
	void output();
	void put(int, int);
	int emptyCell();
	bool isFinish();
	bool update();
	bool checkError();
	bitset<16> setableNumber(int);
	void debug();
private:
	base cells[16];
	base confirmedCells[16];
	void updateConfirmedCells();
	void set(int, int);
	void setConfirmedCells(int, int);
};

#endif
