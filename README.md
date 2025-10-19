# Scrolling Text Display on NeoPixel Strip

Display scrolling alphanumeric messages on a **NeoPixel LED strip** using an **Arduino**. Perfect for **visual notifications**, **decorative displays**, or **DIY signage**.

---

## Features

- Displays customizable scrolling text on a NeoPixel strip
- Fully configurable LED colors for ON/OFF states
- Adjustable scroll speed (`DELAY`)
- Supports letters `A–Z` and symbols `. : ! ?`
- Easily modifiable message via the `originalInput[]` array
- Lightweight and dependency-free (uses only the Adafruit NeoPixel library)

---

## Hardware Requirements

- **Arduino** (Uno, Nano, Mega, or compatible board)
- **Adafruit NeoPixel strip** (60 LEDs recommended)
- **5V power supply** capable of driving the LEDs
- **Data pin** connected to the NeoPixel strip (default: pin `2`)
- **Common ground** between Arduino and LED power supply

---

## Setup

### Install Dependencies

You’ll need the **Adafruit NeoPixel** library. You can install it from the Arduino IDE:

### Connect Hardware

| Arduino Pin | NeoPixel Connection |
| ----------- | ------------------- |
| D2          | DIN (Data In)       |
| 5V          | 5V                  |
| GND         | GND                 |

### Configuration

```
#define PIN 2                            // Arduino pin connected to NeoPixel data line
#define DELAY 500                        // Scroll speed (ms)
#define COLORON display.Color(255,69,0)  // Color for 'ON' pixels (OrangeRed)
#define COLOROFF display.Color(47,79,79) // Color for 'OFF' pixels (DarkSlateGray)
```

```
// Change the Message
char originalInput[] = {'H','E','L','L','O','W','O','R','L','D'}; 
```

### Upload Code

Using for example the Arduino IDE

# Have Fun
