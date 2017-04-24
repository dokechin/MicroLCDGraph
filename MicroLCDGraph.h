#include <Arduino.h>
#include <MicroLCD.h>

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

class MicroLCDGraph
{
public:
    MicroLCDGraph(MicroLCD lcd, *byte bitmap, BYTE_SIZE byte_size);
    void setDomain(int min, int max);
    void draw(const PROGMEM byte* buffer, byte width, byte height);
private:
    *MicroLCD lcd;
    *byte bitmap;
    BYTE_SIZE byte_size;
    int width;
    int min;
    int max;
};


