#include "game.h"
#include <iostream>
#include "SDL.h"
#include "paddle.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : 
      paddleRight(grid_width, grid_height, 1),
      paddleLeft(grid_width, grid_height, 0),
      ball(grid_width, grid_height){}
   

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, paddleLeft, paddleRight);
    Update();
    renderer.Render(ball, paddleLeft, paddleRight);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(scoreLeft, scoreRight, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
  paddleRight.UpdatePaddle();
  paddleLeft.UpdatePaddle();

  int newleft_y = static_cast<int>(paddleLeft.position_y);
  int newRight_y = static_cast<int>(paddleRight.position_y);

  Ball::Hit hit = ball.UpdateBall(newleft_y, newRight_y);

  if (hit == Ball::Hit::hitLeft){
    scoreRight += 1;
  }
  if (hit == Ball::Hit::hitRight){
    scoreLeft += 1;
  }
}

int Game::GetScoreLeft() const { return scoreLeft; }
int Game::GetScoreRight() const { return scoreRight; }
