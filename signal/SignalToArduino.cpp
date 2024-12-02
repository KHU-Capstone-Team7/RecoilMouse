#include "cube.h"
#include "SignalToArduino.h"
#include <assert.h>

void SignalToArduino(Serial& arduinoSerial, const char* Command)
{
    if (arduinoSerial.IsConnected()) {
        arduinoSerial.WriteData(Command, strlen(Command));
    }
    else {
        assert(nullptr);
    }
}