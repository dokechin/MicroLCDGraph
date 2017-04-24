MicroLCDGraph
=====

An Arduino library for drawing Graph on LCD.

This library is depends on the Arduino library MicroLCD:
https://github.com/stanleyhuangyc/MultiLCD

# Constructor
MicroLCDGraph graph(*lcd, bitmap_x,bitmap_y, bit, y, domain_min, domain_max);

Example
MicroLCDGraph graph(&lcd, 12, 0, 8, 0, 8 ,50);

This initialize MicroLCDGraph to cursor position 12,0(X,Y) on LCD display (&lcd class from MicroLCD).

# Method
draw(*data);
data is array contents of domain.


