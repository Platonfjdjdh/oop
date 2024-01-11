// T_cell.h
#pragma once

#include <iostream>

struct T_cell {
    int i_;
    int j_;

    T_cell(int i, int j);

    bool operator==(const T_cell& c) const;
    bool operator!=(const T_cell& c) const;
};

std::ostream& operator<<(std::ostream& os, const T_cell& cell);
#pragma once
