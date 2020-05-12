#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};


  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Left paddle score: " << game.GetScoreLeft() << "\n";
  std::cout << "Right paddle score: " << game.GetScoreRight() << "\n";

  if (game.GetScoreLeft() == game.GetScoreRight()){
    std::cout << "Tie! \n";
  } else if (game.GetScoreLeft() > game.GetScoreRight()){
    std::cout << "Left wins! \n";
  } else {
    std::cout << "Right wins! \n";
  }


  return 0;
}