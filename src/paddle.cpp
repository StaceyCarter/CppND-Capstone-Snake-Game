#include "paddle.h"
#include <cmath>
#include <iostream>

void Paddle::UpdatePaddle() {
  UpdatePosition();
}

void Paddle::UpdatePosition() {
  std::cout << "POSITION Y: " << position_y << "\n";
  switch (direction) {
    case Direction::kUp:
      if (position_y - speed < 0){
        position_y = 0;
      } else {
        position_y -= speed;
      }
      break;

    case Direction::kDown:
      std::cout << "GRID HEIGHT: " << grid_height << "\n";
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

// // Inefficient method to check if cell is occupied by snake.
// bool Snake::SnakeCell(int x, int y) {
//   if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
//     return true;
//   }
//   for (auto const &item : body) {
//     if (x == item.x && y == item.y) {
//       return true;
//     }
//   }
//   return false;
// }