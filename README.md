# Esp-troll
 Why not troll your friends?

Troll your friends with a circuit that simulate a keyboard and send some pre-programmed keystrokes, like alt + tab, capslock or even [this](https://www.youtube.com/watch?v=dQw4w9WgXcQ)!

![Device](/miscs/real_one.jpeg "Device")

## Material
 * ESP32 (Should work with esp8266 too)
 * LCD 16x2 with I2C
 * 3 Buttons
 * 4 resistors
   * 3 x 220Ω
   * 1 x 1kΩ (Optional)
 * LED (Optional)
 * Stripboard or breadboard

## Libs Used
 * [Wire](https://www.arduino.cc/en/reference/wire)
 * [LiquidCrystal_I2C](https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/)
 * [BleKeyboard](https://github.com/T-vK/ESP32-BLE-Keyboard)
 * [ezButton](https://www.arduino.cc/reference/en/libraries/ezbutton/)

## Circuit
![Circuit](/miscs/circuit.png "Circuit")

## How use

Upload the esp-troll.ino code to your Esp, power on your Esp and connect to your friend's computer. It should appear with the name **GenericMonitor** (You can change this name in line 7).

Use the buttons 34 and 39 to navegate through the panel, when you find the one that you like, simple press the action button (35).
It works with Linux and Windows, I never tested with Mac. The keyboard is based in english layout

## Functions

| Function            | Description                                                |
|---------------------|------------------------------------------------------------|
| Test                | Just sent a test text                                      |
| Rick                | Send [this](https://www.youtube.com/watch?v=dQw4w9WgXcQ) and press enter                              |
| Random              | Wait 1 or 10 minutes and send any function bellow this one |
| Backspace           | -                                                          |
| Home                | -                                                          |
| Alt + Tab           | -                                                          |
| Ctrl + Alt + Delete | -                                                          |
| Esc                 | -                                                          |
| Enter               | -                                                          |
| Mute                | -                                                          |
| Up                  | Up arrow                                                   |
| GUI                 | Windows button                                             |
| Caps Lock           | -                                                          |
| Logout              | Logout the active user                                     |

## Troubleshooting

### My code do not upload

Check if you are using the GND pin above 5V, if you are using, than change to other GND, like in the [Circuit](https://github.com/ZerepL/esp-troll/blob/main/miscs/circuit.png) pic.
