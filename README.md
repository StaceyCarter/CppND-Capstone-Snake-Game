# CPPND: Pong Game Capstone Project

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

This is my Capstone project for the Udacity C++ nanodegree. It is a clone of the game Pong. The player on the left uses "w" and "s" keys to control their paddle and the player on the right uses the up and down arrows to control their paddle. 

If either player fails to hit the ball with their paddle and it hits their wall, the other player gets a point. Players can continue to play as long as they want. The final scores & winner will print to the console when they exit out of the game.

## Files include: 
* ball.cpp & ball.h: The ball class which keeps track of the current position and velocity of the ball. 
* paddle.h & paddle.cpp: The paddle class that defines the behavior of the paddle.
* renderer.cpp & renderer.h: Handles rendering game objects to the screen. 
* controller.h & controller.cpp: Handles keyboard input.
* game.cpp & game.h: Handles game loop & updates.
* main.cpp: Handles instantiating the game.

## Rubric points addressed 
1. Loops, Functions, I/O: The project accepts user input and processes the input. From line 17-44 in controller.cpp there is the logic to handle key presses from the user to control the left and right paddles.
2. OOP: The project uses OOP techniques - The bal and paddles are separated into different classes with class methods specific to their behavior. (ball.cpp & ball.h and paddle.cpp and paddle.h)
3. OOP: classes use appropriate access specifiers for class members. eg. In ball.h speed and velocity are private members while x and y position coordinates are public. Only the ball itself should be able to update its own velocity. 
4. OOP: member initialization lists: In paddle.h (line 11-15) all class members that depend on argument values are initialised through a member initialization list.
5. Memory Management: Makes use of references in function declarations. In renderer.cpp (line 44) ball is passed by reference to Render. On line 12 in controller.cpp, both paddles & running are passed by reference to HandleInput.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.