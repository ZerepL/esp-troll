#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BleKeyboard.h>
#include <ezButton.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
BleKeyboard bleKeyboard("GenericMonitor");

ezButton buttonUp(34);
ezButton buttonDown(39);
ezButton buttonAction(35);

boolean randomMode = false;
boolean action = false;

int page = 1;
int maxPage = 14;
int randomCount = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  buttonUp.setDebounceTime(50);
  buttonDown.setDebounceTime(50);
  buttonAction.setDebounceTime(50);
  
  bleKeyboard.begin();
}

void loop() {
  buttonUp.loop();
  buttonDown.loop();
  buttonAction.loop();

  if(buttonUp.isPressed()) {
    if (page >= maxPage) {
      page = maxPage;
    } else {
      page++;
    }

    lcd.clear();
  }

  if(buttonDown.isPressed()) {
    if (page <= 1) {
      page = 1;
    } else {
      page--;
    }

    lcd.clear();
  }

  if(buttonAction.isPressed()) {
    action = true;

    if (randomMode) {
      randomMode = false;
      randomCount = 0;
    }

    lcd.clear();
  }

  lcd.setCursor(0, 0);

  if (randomMode) {

    if (randomCount <= 0) {
      randomCount = random(2400, 24000); // Each loop take ~25 ms - (1 minute to 10 minutes)
      
      page = random(4, maxPage);
      action = true;

      lcd.clear();
    }
    
    randomCount--;
  }
  
  switch (page) {
    case 1:
    
    if (action) {
        bleKeyboard.print("test");

        action = false;
      }
    
      lcd.print("test");
      break;
      
    case 2:

      lcd.print("rick");
      
      if (action) {
        bleKeyboard.print("youtube.com/watch");
        delay(100);
        bleKeyboard.print("?v=dQw4w9WgXcQ");
        delay(100);
        bleKeyboard.press(KEY_NUM_ENTER);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;
      
    case 3:
      lcd.print("random");

      if (action) {
        randomMode = true;
      }

      break;
      
    case 4:
      lcd.print("backspace");

      if (action) {
        bleKeyboard.press(KEY_BACKSPACE);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;
      
    case 5:
      lcd.print("home");
      
      if (action) {
        bleKeyboard.press(KEY_HOME);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
    
      break;

     case 6:
      lcd.print("alt + tab");

      if (action) {
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_TAB);
        delay(100);
        bleKeyboard.release(KEY_TAB);
        delay(100);
        bleKeyboard.press(KEY_TAB);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
    
      break;

    case 7:
      lcd.print("ctrl + alt + del");

      if (action) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_DELETE);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;
      
    case 8:
      lcd.print("esc");

      if (action) {
        bleKeyboard.press(KEY_ESC);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;
      
    case 9:
      lcd.print("enter");

      if (action) {
        bleKeyboard.press(KEY_NUM_ENTER);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;

    case 10:
      lcd.print("mute");

      if (action) {
        bleKeyboard.press(KEY_MEDIA_MUTE);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;

    case 11:
      lcd.print("up");

      if (action) {
        bleKeyboard.press(KEY_UP_ARROW);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;

    case 12:
      lcd.print("GUI");

      if (action) {
        bleKeyboard.press(KEY_LEFT_GUI);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;

    case 13:
      lcd.print("caps lock");

      if (action) {
        bleKeyboard.press(KEY_CAPS_LOCK);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;

    case 14:
      lcd.print("logout");

      if (action) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_DELETE);
        delay(100);
        bleKeyboard.releaseAll();
        delay(100);
        bleKeyboard.press(KEY_RIGHT_ARROW);
        bleKeyboard.release(KEY_RIGHT_ARROW);
        delay(100);
        bleKeyboard.press(KEY_NUM_ENTER);
        delay(100);
        bleKeyboard.releaseAll();

        action = false;
      }
      
      break;
  }

  lcd.setCursor(0, 1);
  
  if (randomMode) {
    lcd.print("Random ON");
  } else {
    lcd.printf("Page %d", page);
  }
  
}