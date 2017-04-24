MicroLCDGraph
=============

An Arduino library for drawing Graph on LCD.

This library is depends on the Arduino library MicroLCD:
https://github.com/stanleyhuangyc/MultiLCD

Usage
-----

# Constractor

MicroLCDGraph graph(*lcd lcd, BYTE_SIZE size, byte width);

# method

```C++
domain(int min, int max);
draw(*int data, byte width, byte height);
```

# example

```C++

#include <Wire.h>
#include <MicroLCD.h>
#include <MicroLCDGraph.h>

LCD_SSD1306 lcd; /* for SSD1306 OLED module */
MicroLCDGraph lcd_graph(&lcd, BYTE_SIZE_1, 5);

void setup()
{
    lcd.begin();
}

void loop()
{
    int data[] = {98, 70, 28, 30, 60};
    lcd.clear();
    lcd_graph.domain(0,100);

    while(){
        lcd_graph.draw(data, 48, 0);
        for (int i=0;i<5;i++){
            data[i] = random(0,101);
        }
        delay(2000);
    }

}

```
