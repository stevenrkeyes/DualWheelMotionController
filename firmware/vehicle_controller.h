#ifndef vehicle_controller_h
#define vehicle_controller_h

/*
Class Name: VehicleController 
Description: motion controller for the overall motion of the vehicle
*/
class VehicleController {
  public:
	// possible goals for the controller to meet
    float x_desired;  // robot global X position in meters
    float y_desired;  // robot global Y position in meters
	float phi_desired; // robot global heading in radians
    
    void update(float dThetaL, float dThetaR); //update the value

  private:
    float phi_delta; // orientation angle phi increment in radians
    float phi_previous; // previous orientation angle phi value in radians
    float x_delta;  // robot X position increment in meters
    float y_delta; // robot Y position increment in meters
    float x_previous; // previous robot X position
    float y_previous; // previous robot Y position
};

#endif

