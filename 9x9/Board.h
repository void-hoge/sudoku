#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <bitset>
using namespace std;

#define base bitset<81>

class Board{
public:
	Board();
	void input();
	void output();
	void put(int, int);
	bool update();
	bitset<9> setableNumber(int);
	int emptyCell();
	bool isFinish();
private:
	base cells[9];
	base confirmedCells[9];
	void set(int, int);
	void updateConfirmedCells();
	void setConfirmedCells(int, int);
	bool checkError();
};

#endif
