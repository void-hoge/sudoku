#ifndef BOARD_FACADE_H
#define BOARD_FACADE_H

#include <array>
#include "param.h"
#include "16x16/Board/Board16.hpp"

using board_expression = std::array<int, all_cells_count>;

// reinterpret Board data to unified type (board_expression)
board_expression compile(b16::Board& b);
board_expression compile(b16::Board&& b);

#endif // BOARD_FACADE_H
