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
    byte line[byte_size];
    line[0] = 0x01;
    for (int i=0;i< data_length;i++){
        int shift = byte_size * ( data[i] - min ) / (max - min);
        shift_left(line, byte_size, shift);
        for(int j=0;j<byte_size;j++){
            bitmap[i + j* width] = line[j];
        }
    }
    lcd.draw(bitmap, width, height);
}

void shift_left(unsigned char *ar, int size, int shift)
{
    int carry = 0;
    while (shift--) {
        for (int i = size - 1; i >=0; --i) {
            int next = (ar[i] & 0x80) ? 0x01 : 0;
            ar[i] = carry | (ar[i] << 1);
            carry = next;
        }   
    }
}
