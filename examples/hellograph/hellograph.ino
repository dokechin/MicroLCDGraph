#include <MicroLCD.h>
#include <MicroLCDGraph.h>

byte bitmap[16 * 5 /8] = {
 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00
};

LCD_SSD1306 lcd; /* for SSD1306 OLED module */

void setup()
{
    lcd.begin();
    Serial.begin(115200);
}

void loop()
{
    MicroLCDGraph lcd_graph(&lcd, bitmap, BYTE_SIZE_2, 5);

    int data[] = {98, 70, 28, 30, 60};
    lcd.clear();
    lcd_graph.setDomain(0,100);

    while(1){
        lcd.setCursor(40, 1);
        lcd_graph.draw(data);
        for (int i=0;i<5;i++){
            data[i] = random(0,101);
        }
        delay(2000);
    }

}