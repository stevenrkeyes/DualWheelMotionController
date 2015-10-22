#ifndef PID_H
#define PID_H

class PID
{
  protected:
  // PID Gains
  float K_P;
	float K_I;
	float K_D;
	// Error memory for controller
	float current_error = 0;
	float previous_error = 0;
	float total_error = 0;
	// Integrator limits;
	float integrator_max = 3.4028235E+38;
	float integrator_min = -3.4028235E+38;
  
  public:
    // Constructor
    PID(float P, float I, float D);
    
    float update(float error);
	
	// TODO: add setters and getters for the variables that people might want to adjust
};

#endif
