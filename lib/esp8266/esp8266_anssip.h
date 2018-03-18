#ifndef ESP8266_ANSSIP_H
#define ESP8266_ANSSIP_H

#include <SoftwareSerial.h>
#include "Arduino.h"

class esp8266
{
    public:
        esp8266(int rx_pin, int tx_pin);
        void begin(int baud);
        int available();
        int wait_readable(int wait_time);
        void at_checking();         //AT -> OK
        void reset_modul();         //AT+RST -> OK
        void set_mode();            //AT+CWMODE=<1-3> -> OK, mode: 1.client, 2.ap_mode, 3.both
        void list_ap();             //AT+CWLAP -> +CWLAP:...\n NULL\n OK
        void connect_ap();          //AT+CWJAP="ssid","pwd" -> OK, if ap is off return +CWJAP:3\n NULL\n FAIL
        void get_ip();              //AT+CIFSR -> +CIFSR:...\n NULL\n OK
        void connect_server();      //AT+CIPSTART="TCP","IPADDRES",PORT -> CONNECT\n NULL\n OK
        void connect_status();      //AT+CIPSTATUS -> STATUS:<code>\n NULL\n OK : mode> 2.got ip, 3.connected, 4.disconnected, 5.didn't get ip
        void send();                //AT+CIPSEND=<datalen> -> '>' then send the data as long as the datalen -> SEND OK
        void disconnect();          //AT+CIPCLOSE -> CLOSE\n NULL\n OK

    private:
        SoftwareSerial* serialesp;
};

#endif
