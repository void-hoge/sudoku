#include "board_facade.h"
#include "param.h"

BoardFacade::BoardFacade(v16::Board& board): board_m{board} { }

BoardFacade::BoardFacade(v16::Board&& board): board_m{board} { }

std::array<int, all_cells_count> BoardFacade::compile() {
    std::array<int, all_cells_count> ret;
    for (auto i=0; i<all_cells_count; ++i) {
        ret.at(i) = board_m.check(i);
    }
    return ret;
}
