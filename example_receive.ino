#include"IM920.hpp"

String data;

void setup()
{
  IM920::setup();
  Serial.begin(19200);
}

void loop()
{
  data = IM920::receive();
  Serial.print(data);
}