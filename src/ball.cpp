#include "ball.h"
#include <cmath>
#include <iostream>



Ball::Hit Ball::UpdateBall(int newLeftY, int newRightY) {
    bool hitLeftWall{false};
    bool hitRightWall{false};

    // Check left paddle or wall
   if (x_velocity < 0){
       // Hits paddle
       if (position_x + x_velocity <= 1 && position_y + 0.5 >= newLeftY && position_y <= newLeftY + 4){
           std::cout << "HIT LEFT PADDLE \n";
           x_velocity = speed;
       }

       // Hits wall
       if (position_x + x_velocity <= 0){
        x_velocity = speed;
        hitLeftWall = true;
        }
   }
   
   // Check right paddle or wall
   if (x_velocity > 0){
       if (position_x + x_velocity >= grid_width - 2 && position_y + 0.5 >= newRightY && position_y <= newRightY + 4){
           std::cout << "HIT RIGHT PADDLE \n";
           x_velocity = -speed;
       }

       // Hits wall
       if (position_x + x_velocity >= grid_width - 1){
        x_velocity = -speed;
        hitRightWall = true;
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

    if (hitLeftWall) {
        return Hit::hitLeft;
    }
    if (hitRightWall){
        return Hit::hitRight;
    } else {
        return Hit::hitNone;
    }

}