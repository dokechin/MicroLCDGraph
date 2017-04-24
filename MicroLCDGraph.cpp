#include "MicroLCDGraph.h"

MicroLCDGraph::MicroLCDGraph(*MicroLCD lcd, *byte bitmap, BYTE_SIZE size){
    this.lcd = lcd;
    this.bitmap = bitmap;
    this.width = buffer.size / size;
    byte_size = size;
}

void MicroLCDGraph::setDomain(int min, int max)
{
    this.min = min;
    this.max = max;
}

void MicroLCDGraph::draw(*int data, byte width, byte height)
{
    int line[byte_size];
    line[0] = 1;
    for (int i=0;i< data_length;i++){
        int shift = byte_size * ( data[i] - min ) / (max - min);
        line << shift;
        for(int j=0;j<byte_size;j++){
            bitmap[i + j* width] = line[j];
        }
    }
    lcd.draw(bitmap, width, height);
}
