#include "board_facade.h"
#include "../../16x16/Board.h"

BoardFacade::BoardFacade(): openBoard {} {
}

BoardFacade::OpenBoard::CellsArray BoardFacade::OpenBoard::getConfirmed() const noexcept {
    CellsArray ret;
    for(auto i=0; i < 16; ++i) {
        ret.at(i) = confirmedCells[i];
    }
    return ret;
}
