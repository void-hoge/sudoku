#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include <array>
#include "param.h"
#include "../../16x16/Board/Board.h"

class BoardFacade {
        Board board_m;
    public:
        using board_expression = std::array<int, all_cells_count>;
        BoardFacade(Board& board);
        BoardFacade(Board&& board = Board());

        board_expression compile();
};

#endif // BOARD_FACADE_H
