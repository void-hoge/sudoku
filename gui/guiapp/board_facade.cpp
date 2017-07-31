#include "board_util.h"
#include "param.h"

board_expression compile(Board& b) {
    return compile(std::move(b));
}

board_expression compile(Board&& b) {
    std::array<int, all_cells_count> ret;
    for (auto i=0; i<all_cells_count; ++i) {
        ret.at(static_cast<size_t>(i)) = b.check(i);
    }
    return ret;
}
