#include "coordinate.h"

Coordinate& Coordinate::move(int direction) {
    x += dx[direction];
    y += dy[direction];
    return *this;
}

int Coordinate::getX() {
    return x;
}

int Coordinate::getY() {
    return y;
}

