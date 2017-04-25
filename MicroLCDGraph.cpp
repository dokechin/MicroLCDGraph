#include <MicroLCDGraph.h>

MicroLCDGraph::MicroLCDGraph (LCD_Common *lcd, byte *bitmap, BYTE_SIZE size){
    _lcd = lcd;
    _bitmap = bitmap;
    data_size = sizeof(bitmap) / size;
    byte_size = size;
}

void MicroLCDGraph::setDomain(int min, int max)
{
    _min = min;
    _max = max;
}

void MicroLCDGraph::draw(int *data, byte width, byte height)
{
    byte line[byte_size];
    line[0] = 0x01;
    for (int i=0;i< data_size;i++){
        int shift = 8 * byte_size * ( data[i] - _min ) / (_max - _min);
        shift_left(line, byte_size, shift);
        for(int j=0;j<byte_size;j++){
            _bitmap[i + j* width] = line[j];
        }
    }
    _lcd->draw(_bitmap, width, height);
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
