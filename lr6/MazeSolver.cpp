#include "MazeSolver.h"

#include <iostream>
#include <algorithm>

const int OPEN_VAL = 0;
const int CLOSE_VAL = 1;
const int START_VAL = -1;


T_path_node::T_path_node(T_cell prev_cell, T_cell cur_cell) : prev_cell_(prev_cell), cur_cell_(cur_cell) {}

bool MazeSolver::fillStack(T_path_stack& path_stack) {
    const int m = 9;
    const int n = 9;
    int labirint[][n] = {
            {1, 0, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 0, 0, 0, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 1, 0, 0, 0, 1, 1, 1, 1},
            {1, 1, 1, -1, 1, 1, 1, 1, 1}
    };

    for (int cur_cell_val = START_VAL;; --cur_cell_val) {
        int start_stack_size = path_stack.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (labirint[i][j] == cur_cell_val) {
                    for (int i_sosed = std::max(i - 1, 0); i_sosed <= std::min(i + 1, m - 1); ++i_sosed) {
                        for (int j_sosed = std::max(j - 1, 0); j_sosed <= std::min(j + 1, n - 1); ++j_sosed) {
                            if ((i_sosed == i || j_sosed == j) && labirint[i_sosed][j_sosed] == OPEN_VAL) {
                                labirint[i_sosed][j_sosed] = cur_cell_val - 1;
                                path_stack.push(T_path_node(T_cell(i, j), T_cell(i_sosed, j_sosed)));

                                if (i_sosed == 0 || i_sosed == m - 1 || j_sosed == 0 || j_sosed == n - 1) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (path_stack.size() == start_stack_size)
            return false;
    }
}
void MazeSolver::printPath(T_path_stack path_stack) {

    std::vector<T_cell> path_sequence;
    path_sequence = getPath(path_stack);
    std::cout << "The route in the maze from the starting cage to the exit:" << std::endl;
    for (auto it = path_sequence.rbegin(); it != path_sequence.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}

std::vector<T_cell> MazeSolver::getPath(T_path_stack path_stack) {
    //std::cout << "Маршрут в лабиринте от выхода до стартовой клетки:" << std::endl;

    // Создаем вектор для сохранения последовательности
    std::vector<T_cell> path_sequence;

    for (;;) {
        T_cell prev_cell = path_stack.top().prev_cell_;
        //std::cout << path_stack.top().cur_cell_ << std::endl;
        path_sequence.push_back(path_stack.top().cur_cell_);
        if (path_stack.size() == 1) {
            //std::cout << path_stack.top().prev_cell_ << std::endl;
            path_sequence.push_back(path_stack.top().prev_cell_);
            return path_sequence;
        }
        while (path_stack.top().cur_cell_ != prev_cell) {
            path_stack.pop();
        }
    }
}
