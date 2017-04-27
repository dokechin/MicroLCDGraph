#include "MicroLCDGraph.h"

// fonts data
const PROGMEM unsigned char bar8[][1] = {
    0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff
};

const PROGMEM unsigned char bar16[][2] = {
    {0x00,0x01},{0x00,0x03},{0x00,0x07},{0x00,0x0f},{0x00,0x1f},{0x00,0x3f},{0x00,0x7f},{0x00,0xff}
    {0x01,0xff},{0x03,0x07},{0x07,0xff},{0x0f,0xff},{0x1f,0x3f},{0x3f,0x7f},{0x7f,0xff},{0xff,0xff}
};

MicroLCDGraph::MicroLCDGraph (LCD_Common *lcd, BYTE_SIZE size){
    _lcd = lcd;
    _byte_size = size;
}

void MicroLCDGraph::setDomain(int min, int max)
{
    _min = min;
    _max = max;
}

void MicroLCDGraph::draw(int *data, byte data_length)
{
    for (int i=0;i< data_length;i++){
        int shift = 8 * _byte_size * ( data[i] - _min ) / (_max - _min);
        if (shift > 8 * _byte_size){
            shift = (8 * _byte_size);
        }
        byte *bar;
        switch(_byte_size){
            case BYTE_SIZE_1:
                bar = bar8;
                break;
            case BYTE_SIZE_2:
                bar = bar16;
                break;
        }
        _lcd->draw(bar[shift], 1, _byte_size * 8);
    }
}

