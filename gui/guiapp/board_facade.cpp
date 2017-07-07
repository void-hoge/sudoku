#include "board_facade.h"
#include "param.h"

BoardFacade::BoardFacade(Board& board): board_m{board} { }

BoardFacade::BoardFacade(Board&& board): board_m{board} { }

void BoardFacade::update() {
    board_m.update();
}

std::array<int, all_cells_count> BoardFacade::checked_array() {
    std::array<int, all_cells_count> ret;
    for (auto i=0; i<all_cells_count; ++i) {
        ret.at(i) = board_m.check(i);
    }
    return ret;
}
