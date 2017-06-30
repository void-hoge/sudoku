#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include <array>
#include "../../16x16/Board.h"

class BoardFacade {
    public:
        BoardFacade();
    private:
        class OpenBoard : private Board {
            public:
                using CellsArray = std::array<std::bitset<256>, 16>;
                CellsArray getConfirmed() const noexcept;
        } openBoard;
};

#endif // BOARD_FACADE_H
