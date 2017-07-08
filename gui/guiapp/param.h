#ifndef PARAM_H
#define PARAM_H

#include <array>

constexpr int eachside = 16;
constexpr int all_cells_count = eachside*eachside;

using board_expression = std::array<int, all_cells_count>;

#endif // PARAM_H
