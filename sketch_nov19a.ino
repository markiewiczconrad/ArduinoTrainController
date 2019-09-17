#include <TimerFreeTone.h>
#include <LiquidCrystal.h>
#include <IRremote.h>

/* A driver program for a model train set.  Designed to be used with two arduino unos.  This is the controller portion.
Please see the included writeup for more information, including parts used.  */

int ir_pin = 8;
IRrecv receiver(ir_pin);
decode_results results;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();

  lcd.begin(16, 2);
  lcd.print("Ready!");
}

void loop() {
  if (receiver.decode(&results))
  {
    /*if (results.value != 4294967295)
      Serial.println(results.value);*/
    if (results.value == 16712445)
    {
      Serial.print("F");
      lcd.clear();
      lcd.print("Going forward!");
      TimerFreeTone(A3, 440, 50);
    }
    else if (results.value == 16720605)
    {
      Serial.print("R");
      lcd.clear();
      lcd.print("Going in reverse!");
      TimerFreeTone(A3, 440, 50);
    }
    else if (results.value == 16761405)
    {
      Serial.print("B");
      lcd.clear();
      lcd.print("Stopping!");
      TimerFreeTone(A3, 440, 50);
    }
    else if (results.value == 16769055)
    {
      Serial.print("S");
      lcd.clear();
      lcd.print("Track is straight!");
      TimerFreeTone(A3, 440, 50);
    }
    else if (results.value == 16754775)
    {
      Serial.print("C");
      lcd.clear();
      lcd.print("Track is curved!");
      TimerFreeTone(A3, 440, 50);
    }
    else if (results.value == 16748655)
    {
      Serial.print("L");
      lcd.clear();
      lcd.print("Lights!");
      TimerFreeTone(A3, 440, 50);
    }
    receiver.resume();
  }
}
