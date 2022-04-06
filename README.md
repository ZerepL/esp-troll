# Esp-troll
 Why not troll your friends?

Troll your friends with a circuit that simulate a keyboard and send some pre-programmed keystrokes, like alt + tab, capslock or even a Rick roll!

## Material
 * ESP32 (Should work with esp8266 too)
 * LCD 16x2 with I2C
 * 3 Buttons
 * 4 resistors (1kΩ or 220Ω, only 3 required)
 * LED (Opcional)
 * Breadboard

## Libs Used
 * Wire
 * LiquidCrystal_I2C
 * BleKeyboard
 * ezButton

## Circuit
![Circuit](/miscs/circuit.png "Circuit")

## How use

Upload the esp-troll.ino code to your Esp, connect to your friend's computer and power on your Esp. You should use the buttons 34 and 39 to navegate through the panel, when you find a one that you like, simple press the action button (35).
It works with Linux and Windows, I never tested with Mac.

## Functions

| Function            | Description                                                |
|---------------------|------------------------------------------------------------|
| Test                | Just sent a test text                                      |
| Rick                | Send [this](https://www.youtube.com/watch?v=dQw4w9WgXcQ) and press enter                              |
| Random              | Wait 1 or 10 minutes and send any function bellow this one |
| Backspace           | -                                                          |
| Home                | -                                                          |
| alt + tab           | -                                                          |
| Ctrl + alt + delete | -                                                          |
| Esc                 | -                                                          |
| Enter               | -                                                          |
| Mute                | -                                                          |
| Up                  | Up arrow                                                   |
| GUI                 | Windows button                                             |
| Caps Lock           | -                                                          |
| Logout              | Logout the active user                                     |

## Troubleshooting

### My code do not upload

Check if you are using the GND pin above 5V, if you are using, than change to other one, like in the Circuit pic.

### I'm stuck in random mode

Press "EN" to reset your Esp

## TODO

 * Find a way to exit from random mode.