#ifndef PADDLE_H
#define PADDLE_H

#include <vector>
#include "SDL.h"

class Paddle {
 public:
  enum class Direction { kUp, kDown, still };

  Paddle(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        position_x(grid_width / 2),
        position_y(grid_height / 2) {}

  void UpdatePaddle();

  Direction direction = Direction::still;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float position_x;
  float position_y;

 private:
  void UpdatePosition();

  int grid_width;
  int grid_height;
};

#endif