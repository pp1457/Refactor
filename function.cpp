#include<iostream>
#define SIZE 105

using namespace std;
 
void input(int &n, int &m, int grid[SIZE][SIZE], bool isCorner[SIZE][SIZE]) {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        isCorner[x][y] = 1;
    }
}

bool valid(int x, int y, int grid[SIZE][SIZE]) {
    if (x < 0 || y < 0 || grid[x][y] != 1) return false;
    return true;
}

void identify(int x, int y, int grid[SIZE][SIZE]) {
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
    int n, m; 
    int grid[SIZE][SIZE];
    bool isCorner[SIZE][SIZE] {{0}};

    input(n, m, grid, isCorner);

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
        if (isCorner[i][j])         
            identify(i, j, grid); 
}
