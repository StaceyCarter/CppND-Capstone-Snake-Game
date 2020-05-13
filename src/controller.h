#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "paddle.h"

class Controller {
 public:
  void HandleInput(bool &running, Paddle &paddleLeft, Paddle &paddleRight) const;

 private:
    void ChangePaddleDirection(Paddle &paddle, Paddle::Direction input) const;
};

#endif