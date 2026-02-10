#ifndef MODBUSWRAPPERS_MODBUSLOGGER_H
#define MODBUSWRAPPERS_MODBUSLOGGER_H
#include <fstream>
#include "utils/baseutils.h"

enum Operation {
    GETIP,
    GETPORT,
    GETMODBUSID,
    CONNECT,
    DISCONNECT,
    ISCONNECTED,
    ADDSLAVE,
    REMOVESLAVE,
    SETENABLED,
    ISENABLED,
    SETSOPENED,
    ISOPENED,
    READHOLDINGREGISTERS,
    WRITEHOLDINGREGISTERS,
    CHECKCONNECTIONSTATUSBYRESPONSE,
    CHANGESTATE,
    ADDSTATE,
    ADDCONNECTABLE,
    SENDCONNECTIONSTATUS,
    PROCESS
};

class ModbusLogger {
    public:
        ModbusLogger(std::string &fileName);
        ~ModbusLogger();

    void Log(ConnectionStatus &connectionStatus, DeviceState &deviceState, Operation &operation);
    void WriteToStream(std::string &logline);
    void CloseStream();

private:
    std::ofstream _logstream;
};




#endif //MODBUSWRAPPERS_MODBUSLOGGER_H