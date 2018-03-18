#include "Arduino.h"
#include "esp8266_anssip.h"


esp8266::esp8266(int rx_pin, int tx_pin)
{
  serialesp = new SoftwareSerial(rx_pin, tx_pin);
}

void esp8266::begin(int baud)
{
  serialesp->begin(baud);
}

int esp8266::available()
{
  return serialesp->available();
}

int esp8266::wait_readable(int wait_time)
{
  return 0;
}
