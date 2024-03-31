#include "grid.h"
#include <vector>
#include <iostream>

using namespace std;

Grid::Grid(){}

void Grid::input() {
    cin >> n;
    notEmpty.resize(n);
    isCorner.resize(n);
    for (int i = 0; i < n; i++) {
        notEmpty[i].resize(n);
        isCorner[i].resize(n);
        for (int j = 0; j < n; j++) {
            isCorner[i][j] = 0;
            int x; cin >> x;
            notEmpty[i][j] = (x==1);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        isCorner[x][y] = 1;
    }
}

bool Grid::valid(Coordinate c) {
    int x = c.getX(), y = c.getY();
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (!notEmpty[x][y]) return false;
    return true;
}

void Grid::identify(Coordinate c) {
    int v {0}, h {0};
    Coordinate tmp = c;

    for (int k = 0; k < 4; k++) {
        tmp = c;
        while (valid(tmp.move(k))) {
            v += dx[k];
            h += dy[k];
        }
    }

    int type {(v>0?2:0) + (h*v>0?1:0)};
    cout << type << " " << abs(v)+1 << " " << abs(h)+1 << endl;
}

void Grid::work() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        if (isCorner[i][j]) 
            identify(Coordinate(i, j));
}
