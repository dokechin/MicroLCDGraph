MicroLCDGraph
=============

An Arduino library for drawing Graph on LCD.

This library is depends on the Arduino library MicroLCD:
https://github.com/stanleyhuangyc/MultiLCD

# Constructor

```C++
MicroLCDGraph graph(LCD_Common *lcd, byte *bitmap, BYTE_SIZE size);
```

# Method

```C++
setDomain(int min, int max);
draw(int *data, byte width, byte height);
```

# example

```C++

#include <MicroLCD.h>
#include <MicroLCDGraph.h>

byte bitmap[16 * 5 /8] = {
 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00
};

LCD_SSD1306 lcd; /* for SSD1306 OLED module */
MicroLCDGraph lcd_graph(&lcd, bitmap, BYTE_SIZE_2);

void setup()
{
    lcd.begin();
}

void loop()
{
    int data[] = {98, 70, 28, 30, 60};
    lcd.clear();
    lcd_graph.setDomain(0,100);

    while(1){
        lcd_graph.draw(data, 48, 0);
        for (int i=0;i<5;i++){
            data[i] = random(0,101);
        }
        delay(2000);
    }

}

```
