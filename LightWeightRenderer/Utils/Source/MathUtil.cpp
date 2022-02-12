//
// Created by MisThe on 2022/1/20.
//

#include "../Head/MathUtil.h"

bool MathUtil::int2::equal(MathUtil::int2 num) {
    if ((num.x == this->x) && (num.y == this->y))
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const MathUtil::int2 &int2) {
    os << "x: " << int2.x << " y: " << int2.y;
    return os;
}

bool MathUtil::double2::equal(double2 num) {
    if ((abs(num.x - this->x) < 0.000001) && (abs(num.y - this->y) < 0.00001))
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const MathUtil::double2 &double2) {
    os << "x: " << double2.x << " y: " << double2.y;
    return os;
}
