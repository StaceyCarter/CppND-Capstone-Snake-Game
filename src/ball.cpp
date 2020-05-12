#include "ball.h"
#include <cmath>
#include <iostream>


void Ball::UpdateBall(int newLeftX, int newLeftY, int newRightX, int newRightY) {

    // Check left paddle or wall
   if (x_velocity < 0){
       // Hits paddle
       if (position_x + x_velocity <= 1 && position_y >= newLeftY && position_y <= newLeftY + 4){
           std::cout << "HIT LEFT PADDLE \n";
           x_velocity = speed;
       }

       // Hits wall
       if (position_x + x_velocity <= 0){
        x_velocity = speed;
        }
   }
   
   // Check right paddle or wall
   if (x_velocity > 0){
       if (position_x + x_velocity >= grid_width - 2 && position_y >= newRightY && position_y <= newRightY + 4){
           std::cout << "HIT RIGHT PADDLE \n";
           x_velocity = -speed;
       }

       // Hits wall
       if (position_x + x_velocity >= grid_width - 1){
        x_velocity = -speed;
        }
   }

   if (position_y + y_velocity <= 0){
       y_velocity = speed; 
   } 
   if (position_y + y_velocity >= grid_height - 1){
       y_velocity = -speed;
   }
   position_y += y_velocity;
   position_x += x_velocity;
}