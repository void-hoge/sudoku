#include "board_facade.h"
#include "../../16x16/Board.h"

BoardFacade::BoardFacade(): openBoard {} {
}

BoardFacade::OpenBoard::CellsArray BoardFacade::OpenBoard::getConfirmed() const noexcept {
    CellsArray ret;
    std::copy(std::begin(confirmedCells), std::end(confirmedCells), ret.begin());
    return ret;
}
