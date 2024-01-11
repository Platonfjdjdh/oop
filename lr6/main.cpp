#include <iostream>
#include "T_cell.h"
#include "MazeSolver.h"


int main() {
    MazeSolver mazeSolver;
    T_path_stack path_stack;


    if (!mazeSolver.fillStack(path_stack)) {
        std::cout << "No  exit!" << std::endl;
    }
    else {
        mazeSolver.printPath(path_stack);
    }



    return 0;
}
