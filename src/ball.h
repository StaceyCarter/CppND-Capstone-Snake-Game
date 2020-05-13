#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"

class Ball {
 public:
  enum class Hit { hitLeft, hitRight, hitNone};

  Ball(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        position_x(grid_width /3),
        position_y(grid_height / 2){};

  Hit UpdateBall(int newLeftY, int newRightY);

  float position_x;
  float position_y;

 private:
  void UpdatePosition();
  int grid_width;
  int grid_height;

  float speed{0.2f};

  float y_velocity{speed};
  float x_velocity{speed};
};

#endif