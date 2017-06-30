#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include "../../16x16/Board.h"

class BoardFacade {
    public:
        BoardFacade();
    private:
        class OpenBoard : private Board {
        } openBoard;
};

#endif // BOARD_FACADE_H
