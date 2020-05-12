#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "paddle.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Paddle &paddle) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
    void ChangePaddleDirection(Paddle &paddle, Paddle::Direction input) const;
};

#endif