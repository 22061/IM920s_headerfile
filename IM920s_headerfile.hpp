#ifndef IM920_HPP_
#define IM920_HPP_

#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial IM920Serial(8, 9);    // RX, TX
StaticJsonDocument<200> doc;

char send_data[50];
char input[50];
String receive_data;
int i = 0;

namespace IM920
{
  inline void setup(void) 
  {
    IM920Serial.begin(19200);
    pinMode(10, INPUT_PULLUP);
  }

  inline void send(String number, int send_1, int send_2) 
  {    
    if(digitalRead(10) == LOW)
    {
      doc["data1"] = send_1;
      doc["data2"] = send_2;
      serializeJson(doc, send_data, 50);
      IM920Serial.print("TXDU");
      IM920Serial.print(number);
      IM920Serial.print(",");
      IM920Serial.println(send_data);
    }
  }

  inline String receive(void)
  {
    if(IM920Serial.available()) 
    {
      input[i] = IM920Serial.read();
      if (input[i] == '\n') 
      {
        receive_data = input;
        receive_data = receive_data.substring(11);

        DeserializationError error = deserializeJson(doc, receive_data);

        i = 0;

        return receive_data;
      }
      else
      {
        i++;
      }
    }
  }
}
#endif
