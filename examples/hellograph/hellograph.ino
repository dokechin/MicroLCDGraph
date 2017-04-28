#include <MicroLCD.h>
#include <MicroLCDGraph.h>

LCD_SSD1306 lcd; /* for SSD1306 OLED module */

void setup()
{
    lcd.begin();
}

void loop()
{
    MicroLCDGraph lcd_graph(&lcd, BYTE_SIZE_2);

    int data[] = {98, 70, 28, 30, ß60};
    lcd.clear();
    lcd_graph.setDomain(0,100);

    while(1){
        lcd.setCursor(40, 1);
        lcd_graph.draw(data,5);
        for (int i=0;i<5;i++){
            data[i] = random(0,101);
        }
        delay(2000);
    }

}