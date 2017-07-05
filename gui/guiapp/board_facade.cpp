#include "board_facade.h"
#include "param.h"

BoardFacade::BoardFacade() {

}

std::array<int, all_cells_count> BoardFacade::checked_array() {
    std::array<int, all_cells_count> ret;
    for (auto i=0; i<all_cells_count; ++i) {
        ret.at(i) = check(i);
    }
    return ret;
}
