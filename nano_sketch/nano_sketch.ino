#include <LiquidCrystal.h>

const String version = "Ver B0.0.1";
const bool debug = true;

const int d_reset = 12, d_enable = 11, d_d4 = 5, d_d5 = 4, d_d6 = 3, d_d7 = 2;
LiquidCrystal lcd(d_reset, d_enable, d_d4, d_d5, d_d6, d_d7);

void setup() {
  Serial.begin(9600);
  Serial.println("MiniLCD-Driver");
  Serial.println("\tVersion B0.0.1");

  lcd.begin(16,2);
  lcd.print("MiniLCD-Driver");
  lcd.setCursor(0, 1);
  lcd.print(version);
  delay(3000);
  
  lcd.clear();

  lcd.setCursor(0,0);
  Serial.setTimeout(16);
  lcd.print(version+" T: 16ms");
  lcd.setCursor(0, 1);
  lcd.print("Wait on host");

  Serial.flush();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    if(debug) { Serial.println("rec"); }

    String command = Serial.readString();
    if(debug) {Serial.println(command);}

    char action = command[0];
    if(debug) {Serial.println(action);}

    lcd.clear();
    lcd.setCursor(0, 0);
    
    switch(action)
    {
      case 'f':
          lcd.print("haha hey");
          break;
        case 'b':
          lcd.print("haha no");
          break;
        default: 
          lcd.print("invalid input");
          break;
    }
    
  }
}
