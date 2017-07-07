#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include <array>
#include "param.h"
#include "../../16x16/Board/Board.h"

class BoardFacade {
        Board board_m;
    public:
        BoardFacade(Board& board);
        BoardFacade(Board&& board = Board());

        void update();
        std::array<int, all_cells_count> checked_array();
};

#endif // BOARD_FACADE_H
