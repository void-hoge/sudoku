#ifndef BOARD16_HPP_INCLUDED
#define BOARD16_HPP_INCLUDED

#include <bitset>
#include <vector>

#define uint256 std::bitset<256>

namespace v16 {
    class Board{
    public:
        Board();
        void input();
        void vectorInput(std::vector<int>);
        void output();
        int check(int);
        void put(int, int);
        bool update();
        std::bitset<16> setableNumber(int);
        int emptyCell();
        bool isFinish();
    private:
        uint256 cells[16];
        uint256 confirmedCells[16];
        void set(int, int);
        void updateConfirmedCells();
        void setConfirmedCells(int, int);
        bool checkError();
    };
}

#endif
