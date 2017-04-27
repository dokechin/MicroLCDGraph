#ifndef FLAG_PAD_ZERO
#include <MicroLCD.h>
#endif
#include <Arduino.h>

typedef enum {
    BYTE_SIZE_1 = 1,
    BYTE_SIZE_2 = 2,
} BYTE_SIZE;

class MicroLCDGraph
{
public:
    MicroLCDGraph(LCD_Common *lcd, byte *bitmap, BYTE_SIZE byte_size);
    void setDomain(int min, int max);
    void draw(int *data, byte data_length);
private:
    LCD_Common *_lcd;
    BYTE_SIZE _byte_size;
    int _min;
    int _max;
};