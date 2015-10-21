/*
PID controller
Author: Steven Keyes - srkeyes@mit.edu
Date: Oct. 2015
*/

#include "PID.h"

// Constructor
PID::PID(P, I, D)
{
  K_P = P;
  K_I = I;
  K_D = D;
}

float PID::update(error)
{
  current_error = error;
  
  // compute the P and D controller values
  float p_value = K_P * current_error;
  float d_value = K_D * (current_error - previous_error);
  
  // handle the memory elements of the PID controller
  total_error += current_error;
  previous_error = current_error;
  
  // limit the integrated error to prevent integrator wind-up
  if (total_error > integrator_max)
  {
	total_error = integrator_max;
  }
  else if (total_error < integrator_min)
  {
	total_error = integrator_min;
  }
  
  // compute the I controller value
  float i_value = K_I * total_error;
  
  float pid_value = p_value + i_value + d_value;
  
  return pid_value;
}