#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "paddle.h"


void Controller::ChangePaddleDirection(Paddle &paddle, Paddle::Direction input) const {
  paddle.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Paddle &paddleLeft, Paddle &paddleRight) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_w:
          ChangePaddleDirection(paddleLeft, Paddle::Direction::kUp);
          break;
        case SDLK_s:
          ChangePaddleDirection(paddleLeft, Paddle::Direction::kDown);
          break;

        case SDLK_UP:
          ChangePaddleDirection(paddleRight, Paddle::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangePaddleDirection(paddleRight, Paddle::Direction::kDown);
          break;

      }
    } else if (e.type == SDL_KEYUP) {
      switch (e.key.keysym.sym) {
        case SDLK_s:
        case SDLK_w:
          ChangePaddleDirection(paddleLeft, Paddle::Direction::still);
          break;
        case SDLK_UP:
        case SDLK_DOWN:
          ChangePaddleDirection(paddleRight, Paddle::Direction::still);
          break;
      }
    }
  }
}