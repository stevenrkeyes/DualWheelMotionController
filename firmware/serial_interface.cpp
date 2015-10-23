#include "serial_interface.h"
#include "vehicle_odometry.h"
#include "vehicle_controller.h"

#define SERIAL_FREQ 100
#define SERIAL_PERIOD 0.01
#define SERIAL_PERIOD_MICROS 10000

void SerialInterface::initialize() {
  prevSerialTime = micros();
  return;
}

void SerialInterface::SendUpdateToMaster(VehicleOdometry vehicle_odometry) {
  if (micros() - prevSerialTime >= SERIAL_PERIOD_MICROS) {
    Serial.print(vehicle_odometry.X, 6); //X
    Serial.print(",");
    Serial.print(vehicle_odometry.Y, 6); //Y
    Serial.print(",");
    Serial.print(vehicle_odometry.Phi); //Phi
    Serial.print(",");
    Serial.println(finished ? 1 : 0);
    prevSerialTime = micros();
  }
  return;
}

void SerialInterface::ReceiveCommandsAndUpdateController(VehicleController vehicle_controller) {
    if (Serial.available() > 0) {
      commandString = Serial.readString();
      int i = 0;
      indexPointer = 0;
      while (indexPointer != -1 ) {
        indexPointer = commandString.indexOf(',');
        tempString = commandString.substring(0, indexPointer);
        commandString = commandString.substring(indexPointer+1);
        command[i] = tempString.toFloat();
        ++i;
      }
      commandX = command[0];
      commandY = command[1];
      commandPhi = command[2];
      updateStatus(false);
    }
    return;
  }

void SerialInterface::updateStatus(bool currentStatus) {
  finished = currentStatus;
  return;
}


