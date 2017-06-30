#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <bitset>

#define base std::bitset<256>

class Board{
public:
	Board();
	void input();
	void output();
	void put(int, int);
	bool update();
    std::bitset<16> setableNumber(int);
	int emptyCell();
	bool isFinish();
    int check(int coodinate);
protected:
	base cells[16];
	base confirmedCells[16];
	void set(int, int);
	void updateConfirmedCells();
	void setConfirmedCells(int, int);
	bool checkError();
};

#endif
