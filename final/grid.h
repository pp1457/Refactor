#include "coordinate.h"
#include <vector>

using namespace std;

class Grid {
  private:
    int n, m;
    vector<vector<bool>> notEmpty, isCorner;
    void identify(Coordinate c);
    bool valid(Coordinate c);
  public:
    Grid();
    void input();
    void work();
};


