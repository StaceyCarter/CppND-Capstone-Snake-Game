#include "paddle.h"
#include <cmath>
#include <iostream>

void Paddle::UpdatePaddle() {
  UpdatePosition();
}

void Paddle::UpdatePosition() {
  switch (direction) {
    case Direction::kUp:
      std::cout << "MOVING UP \n\n";
      position_y -= speed;
      break;

    case Direction::kDown:
      position_y += speed;
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