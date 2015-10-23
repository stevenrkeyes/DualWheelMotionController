#ifndef serial_interface_h
#define serial_interface_h

#include "Arduino.h"
#include "vehicle_odometry.h"
#include "vehicle_controller.h"

class SerialInterface {
  public:
    float command[10];
    float commandX;
    float commandY;
    float commandPhi;
    bool finished;
    /*Function Name: initialize();
    Effect: Initialize all public member variables of the class to 0 and prevSerialTime to micro()
    Modifies: All member variables
    Requirement: None
    Input: None
    Output: None
    Usage; Call this function upon instantiation of the class to a global object
    */
    void initialize();
    /*Function Name: sendSerialData(const RobotPosition & robotPos);
    Effect: report serial data to matlab
    Modifies: None
    Requirement: None
    Input: const RobotPosition & robotPos
    Output: None
    Usage; Call this function to check and receive serial data in each timed loop
    */
    void SendUpdateToMaster(VehicleOdometry vehicle_odometry);
    /*Function Name: receiveSerialData();
    Effect: Initialize all public member variables of the class to 0
    Modifies: 
          1. float command[10];
          2. float commandX;
          3. float commandY;
          4. float commandPhi;
    Requirement: None
    Input: None
    Output: None
    Usage; Call this function to send serial data in each timed loop
    */   
    void ReceiveCommandsAndUpdateController(VehicleController vehicle_controller);
    /*Function Name: updateStatus(boolean finished);
    Effect: change the private member variable boolean finished
    Modifies: private member variable boolean finished
    Requirement: None
    Input: boolean status
    Output: None
    Usage; Call this function to update the status to send
    */
    void updateStatus(bool currentStatus);
    
  private:
    unsigned long prevSerialTime;
    String commandString;
    String tempString;
    int indexPointer = 0;
};

#endif

