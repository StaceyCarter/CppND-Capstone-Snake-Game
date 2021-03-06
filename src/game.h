#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "paddle.h"
#include "ball.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScoreLeft() const;
  int GetScoreRight() const;

 private:
  Paddle paddleLeft;
  Paddle paddleRight;
  Ball ball;

  int scoreLeft{0};
  int scoreRight{0};

  void Update();
};

#endif