#include <iostream>
using namespace std;

#include "grid.h"
 
void input(Grid &grid) {
    cin >> grid.n;
    for (int i = 0; i < grid.n; i++) for (int j = 0; j < grid.n; j++) cin >> grid.notEmpty[i][j];
    cin >> grid.m;
    for (int i = 0; i < grid.m; i++) {
        int x, y; cin >> x >> y;
        grid.isCorner[x][y] = 1;
    }
}

bool valid(int x, int y, Grid &grid) {
    if (x < 0 || y < 0 || !grid.notEmpty[x][y]) return false;
    return true;
}

void identify(int x, int y, Grid &grid) {
    int dx[4] {-1, 0, 1, 0}, dy[4] {0, -1, 0, 1};

    int v {0}, h {0};
    int tx, ty;

    for (int k = 0; k < 4; k++) {
        tx = x; ty = y;
        while (valid(tx+dx[k], ty+dy[k], grid)) {
            tx += dx[k];
            ty += dy[k];
            v += dx[k];
            h += dy[k];
        }
    }

    int type {(v>0?2:0) + (h*v>0?1:0)};
    cout << type << " " << abs(v)+1 << " " << abs(h)+1 << endl;
}
 
int main() {
    Grid grid;
    input(grid);

    for (int i = 0; i < grid.n; i++) for (int j = 0; j < grid.n; j++) 
        if (grid.isCorner[i][j])         
            identify(i, j, grid); 
}
