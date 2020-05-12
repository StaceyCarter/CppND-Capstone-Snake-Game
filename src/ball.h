#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"

class Ball {
 public:

  Ball(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        position_x(grid_width /3),
        position_y(grid_height / 2){};

  void UpdateBall(int newLeftX, int newLeftY, int newRightX, int newRightY);

  float speed{0.2f};

  float position_x;
  float position_y;
  float y_velocity{speed};
  float x_velocity{speed};

 private:
  void UpdatePosition();
  int grid_width;
  int grid_height;
};

#endif