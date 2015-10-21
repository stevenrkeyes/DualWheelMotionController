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
	float integrator_max = std::numeric_limits<float>::infinity();
	float integrator_min -std::numeric_limits<float>::infinity();
  
  public:
    // Constructor
    PID(P, I, D);
    
    float update(error);
	
	// TODO: add setters and getters for the variables that people might want to adjust
};

#endif