#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include <array>
#include "param.h"
#include "../../16x16/Board.h"

class BoardFacade: private Board {
    public:
        BoardFacade();
        std::array<int, all_cells_count> checked_array();
};

#endif // BOARD_FACADE_H
