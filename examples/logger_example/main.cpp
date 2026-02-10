#include <iostream>
#include "modbuswrappers/logaddition/modbuslogger.h"



int main() {

    std::string name = "file.txt";
    auto logger = ModbusLogger(name);
    auto conStatus = ConnectionStatus::ConnectionStatus_CONNECTED;
    auto deviceState = DeviceState::DISCONNECTED;
    auto operation = Operation::GETIP;
    logger.Log(conStatus, deviceState, operation);


    return 0;
}
