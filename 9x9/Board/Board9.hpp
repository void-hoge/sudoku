#ifndef BOARD9_HPP_INCLUDED
#define BOARD9_HPP_INCLUDED

#include <bitset>
#include <vector>
#define uint81 std::bitset<81>

namespace v9 {
    class Board{
    public:
        Board();
        void input();
        void vectorInput(std::vector<int>);
        void output();
        int check(int);
        void put(int, int);
        bool update();
        std::bitset<9> setableNumber(int);
        int emptyCell();
        bool isFinish();
    private:
        uint81 cells[9];
        uint81 confirmedCells[9];
        void set(int, int);
        void updateConfirmedCells();
        void setConfirmedCells(int, int);
        bool checkError();
    };
}

#endif
