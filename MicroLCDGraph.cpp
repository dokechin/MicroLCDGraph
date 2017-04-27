#include "MicroLCDGraph.h"

MicroLCDGraph::MicroLCDGraph (LCD_Common *lcd, byte *bitmap, BYTE_SIZE size, byte data_length){
    _lcd = lcd;
    _bitmap = bitmap;
    _byte_size = size;
    _data_length = data_length;
}

void MicroLCDGraph::setDomain(int min, int max)
{
    _min = min;
    _max = max;
}

void MicroLCDGraph::draw(int *data)
{
    byte line[_byte_size];
    for(int i=0;i< _byte_size;i++){
      line[i] = 0;
    }
    line[0] = 0x01;
    for (int i=0;i< _data_length;i++){
        int shift = 8 * _byte_size * ( data[i] - _min ) / (_max - _min);
        if (shift > 8 * _byte_size){
            shift = (8 * _byte_size) - 1;
        }
        shift_left(line, _byte_size, shift);
        
        for(int j=byte_size,k=0;j >= 0 ;j--,k++){
            _bitmap[i + k * _data_length] = line[j];
        }    
    }
    _lcd->draw(_bitmap, _data_length, _byte_size * 8);
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
