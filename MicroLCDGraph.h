#ifndef FLAG_PAD_ZERO
#include <MicroLCD.h>
#endif
#include <Arduino.h>

typedef enum {
    BYTE_SIZE_1 = 1,
    BYTE_SIZE_2 = 2,
    BYTE_SIZE_3 = 3,
    BYTE_SIZE_4 = 4,
    BYTE_SIZE_5 = 5,
    BYTE_SIZE_6 = 6,
    BYTE_SIZE_7 = 7,
    BYTE_SIZE_8 = 8,
    BYTE_SIZE_9 = 9,
    BYTE_SIZE_10 = 10,
    BYTE_SIZE_11 = 11,
    BYTE_SIZE_12 = 12   
} BYTE_SIZE;

void shift_left(unsigned char *ar, int size, int shift);

class MicroLCDGraph
{
public:
    MicroLCDGraph(LCD_Common *lcd, byte *bitmap, BYTE_SIZE byte_size);
    void setDomain(int min, int max);
    void draw(int *data, byte width, byte height);
private:
    LCD_Common *_lcd;
    byte *_bitmap;
    BYTE_SIZE byte_size;
    int data_length;
    int _min;
    int _max;
};