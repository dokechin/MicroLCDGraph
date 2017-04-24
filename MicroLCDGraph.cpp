#include "MicroLCDGraph.h"

MicroLCDGraph::MicroLCDGraph(*MicroLCD lcd, *byte buffer, BYTE_SIZE size){
    this.lcd = lcd;
    this.buffer = buffer;
    this.data_length = buffer.size / size;
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
            buffer[i + j* data_length] = line[j];
        }
    }
    lcd.draw(buffer, width, height);
}
