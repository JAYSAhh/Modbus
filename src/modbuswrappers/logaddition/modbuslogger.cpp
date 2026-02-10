#include "modbuswrappers/logaddition/modbuslogger.h"

#include <iostream>



ModbusLogger::ModbusLogger(std::string &fileName) {
    _logstream = std::ofstream(fileName, std::ios_base::app);
}
ModbusLogger::~ModbusLogger() {
    if (_logstream.is_open()) {
        CloseStream();
    }
}

void ModbusLogger::Log(ConnectionStatus &connectionStatus, DeviceState &deviceState, Operation &operation) {
    auto time = std::time(0);
    auto command = "[" + std::to_string(time) + "]";
    std::cout << time << std::endl;
    WriteToStream(command);
}

void ModbusLogger::WriteToStream(std::string &logline) {
    if (_logstream.is_open()) {
        _logstream << logline<<std::endl;
    }
}

void ModbusLogger::CloseStream() {
    _logstream.close();
}