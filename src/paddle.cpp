#include "paddle.h"
#include <cmath>
#include <iostream>


void Paddle::UpdatePaddle() {
  switch (direction) {
    case Direction::kUp:
      if (position_y - speed < 0){
        position_y = 0;
      } else {
        position_y -= speed;
      }
      break;

    case Direction::kDown:
      if (position_y + speed > (grid_height -3)){
        position_y = grid_height - 3;
      } else {
        position_y += speed;
      }
    
      break;

    case Direction::still:
        position_y = position_y;
        break;
  }
}