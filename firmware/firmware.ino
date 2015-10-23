/*
Dual Wheel Motion Controller

Steven Keyes - srkeyes@mit.edu
& Zack Bright - zbright@mit.edu
& Dan Gonzalez - dgonz@mit.edu
& Fangzhou Xia- xiafz@mit.edu
Oct. 2015
*/

//Include the SPI bus library, the encoder buffer library, and the motor shield library
#include "PID.h"
#include "SPI.h"
#include "LS7366.h"
#include "DualMC33926MotorShield.h"
#include "serial_interface.h"
#include "vehicle_odometry.h"
#include "vehicle_controller.h"

#define FREQ 2000
#define PERIOD 0.0005
#define PERIOD_MICROS 500

float currentTime;
float prevTime;

// object for interpreting commands frmo the master and returning data
SerialInterface serial_interface = SerialInterface();
// object for storing the measurements and state estimated by the robot
VehicleOdometry vehicle_odometry = VehicleOdometry();
// object for computing the motor speeds to acheive a goal state
VehicleController vehicle_controller = VehicleController();

void setup() {
  Serial.begin(115200);      // Initialize Serial Communication
  initEncoders();       Serial.println("Encoders Initialized..."); //initialize Encoders
  clearEncoderCount();  Serial.println("Encoders Cleared..."); //clear Encoder Counts
  currentTime = micros(); //initialize timer
  prevTime = micros(); //initialize timer
  delay(500);// set a delay so the robot doesn't drive off without you
}

void loop() {
  // timed loop implementation
  // TODO: adjust timing loop to be more precise
  if (micros() - prevTime >= PERIOD_MICROS) {
    currentTime = micros();
    prevTime = currentTime; //update timer
    
    // Call the serial interface class to get any updates from the master computer
    // and update the vehicle controller with any changes
    serial_interface.ReceiveCommandsAndUpdateController(vehicle_controller);
    
    // if there are any updates, apply them to the motion controller
    // update odometry
    // calculate error
    // run controller
    // send commands to motors
    
    // send update over serial using the serial interface
    serial_interface.SendUpdateToMaster(vehicle_odometry);
    
  }
}




