#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "paddle.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::ChangePaddleDirection(Paddle &paddle, Paddle::Direction input) const {
  paddle.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, Paddle &paddle) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_w:
          std::cout << "PRESSING W \n\n ";
          // paddle.direction = Paddle::Direction::kUp;
          ChangePaddleDirection(paddle, Paddle::Direction::kUp);
          break;
        case SDLK_s:
          std::cout << "PRESSING S \n\n ";
          ChangePaddleDirection(paddle, Paddle::Direction::kDown);
          break;

        case SDLK_UP:
          // ChangeDirection(snake, Snake::Direction::kUp,
          //                 Snake::Direction::kDown);
          ChangePaddleDirection(paddle, Paddle::Direction::kUp);
          break;

        case SDLK_DOWN:
          // ChangeDirection(snake, Snake::Direction::kDown,
          //                 Snake::Direction::kUp);
          ChangePaddleDirection(paddle, Paddle::Direction::kDown);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    } else if (e.type == SDL_KEYUP) {
      // No key pressed
      ChangePaddleDirection(paddle, Paddle::Direction::still);
    }
  }
}