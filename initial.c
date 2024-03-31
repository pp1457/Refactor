//#define DEBUG
#include<stdio.h>
 
int g[105][105];
 
int x[10005], y[10005], fx[10005], fy[10005];
 
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
 
int main() {
    int n; 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        scanf("%d", &g[i][j]);
    }
 
    int m;
    scanf("%d", &m);
 
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
 
    int curx = 200, cury = 200;
    int who = 200;
 
    for (int i = 0; i < m; i++ ) {
        curx = 200;
        cury = 200;
        who = 200;
        for (int j = 0; j < m; j++) {
            if (curx > x[j]) {
                curx = x[j];
                cury = y[j];
                who = j;
            } else if (curx == x[j] && cury > y[j]) {
                cury = y[j];
                who = j;
            }
        }
 
        fx[i] = curx;
        fy[i] = cury;
        x[who] = 200;
        y[who] = 200;
    }
 
    for (int i = 0; i < m; i++ ) {
        int cx = fx[i], cy = fy[i];
#ifdef DEBUG
        printf("cx = %d cy = %d\n", cx, cy);
#endif
        int va = 0, ha = 0;
        for (int d = 0; d < 4; d++) {
            cx = fx[i]; cy = fy[i];
            if (d == 2 && va) continue;
            if (d == 3 && ha) continue;
            int tx = cx + dx[d], ty = cy + dy[d];
#ifdef DEBUG
            printf("d = %d\n", d);
#endif
            while (tx >= 0 && tx < n && 
                    ty >= 0 && ty < n && g[tx][ty]) {
#ifdef DEBUG
                printf("%d %d\n", tx, ty);
#endif
                cx = tx;
                cy = ty;
                va += dx[d];
                ha += dy[d];
                g[tx][ty] = 0;
                tx = cx + dx[d];
                ty = cy + dy[d];
            }
        }
        if (va < 0 && ha > 0) printf("0 %d %d\n", -va+1, ha+1);
        else if (va < 0 && ha < 0) printf("1 %d %d\n", -va+1, -ha+1);
        else if (va > 0 && ha < 0) printf("2 %d %d\n", va+1, -ha+1);
        else if (va > 0 && ha > 0) printf("3 %d %d\n", va+1, ha+1);
    }
 
 
}
