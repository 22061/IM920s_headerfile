#include"IM920.hpp"

void setup()
{
  IM920::setup();
}

void loop()
{
  String num = "0002";
  int x = 90;
  int y = 180;
  IM920::send(num, x, y);
}