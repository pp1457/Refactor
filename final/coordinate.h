const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

class Coordinate {
  private:
    int x, y;
  public:
    Coordinate(int x, int y): x {x}, y {y} {}
    Coordinate& move(int direction);
    int getX();
    int getY();
};
