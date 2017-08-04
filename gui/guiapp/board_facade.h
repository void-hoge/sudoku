#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include <array>
#include "param.h"
#include "16x16/Board/Board16.hpp"

class BoardFacade {
        v16::Board board_m;
    public:
        using board_expression = std::array<int, all_cells_count>;
        BoardFacade(v16::Board& board);
        BoardFacade(v16::Board&& board = v16::Board());

        board_expression compile();
};

#endif // BOARD_FACADE_H
