// T_cell.cpp
#include "T_cell.h"

T_cell::T_cell(int i, int j) : i_(i), j_(j) {}

bool T_cell::operator==(const T_cell& c) const {
    return i_ == c.i_ && j_ == c.j_;
}

bool T_cell::operator!=(const T_cell& c) const {
    return !(*this == c);
}

std::ostream& operator<<(std::ostream& os, const T_cell& cell) {
    os << "(" << cell.i_ << ", " << cell.j_ << ")";
    return os;
}
