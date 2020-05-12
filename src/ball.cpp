#include "ball.h"
#include <cmath>
#include <iostream>


void Ball::UpdateBall() {
   if (position_y + y_velocity <= 0){
       y_velocity = speed; 
   } 
   if (position_y + y_velocity >= grid_height - 1){
       y_velocity = -speed;
   }
   position_y += y_velocity;

   if (position_x + x_velocity <= 0){
       x_velocity = speed;
   }
   if (position_x + x_velocity >= grid_width - 1){
       x_velocity = -speed;
   }
   position_x += x_velocity;
}