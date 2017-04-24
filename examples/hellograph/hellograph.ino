#include <MicroLCD.h>
#include <MicroLCDGraph.h>

PROGMEN byte bitmap[16 * 5 /8] = {
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
    lcd_graph.domain(0,100);

    while(){
        lcd_graph.draw(data, 48, 0);
        for (int i=0;i<5;i++){
            data[i] = random(0,101);
        }
        delay(2000);
    }

}