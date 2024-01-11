#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "T_cell.h"
#include <stack>
#include <vector>

// Структура представляющая узел пути в лабиринте
struct T_path_node {
    T_cell prev_cell_;
    T_cell cur_cell_;

    T_path_node(T_cell prev_cell, T_cell cur_cell);
};

// Определение типа для стека пути в лабиринте
typedef std::stack<T_path_node> T_path_stack;

class MazeSolver {
public:
    bool fillStack(T_path_stack& path_stack);

    void printPath(T_path_stack path_stack);

    std::vector<T_cell> getPath(T_path_stack path_stack);
};

#endif // MAZE_SOLVER_H
