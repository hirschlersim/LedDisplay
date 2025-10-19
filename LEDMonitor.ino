#include <Adafruit_NeoPixel.h>

/*______________________________________________________________________________________*/
/* Definitions that the User can Change */
#define PIN 2                            // input pin Neopixel is attached to
#define DELAY 500                        // delay beetween display updates
#define COLORON display.Color(255,69,0)  // the color a "ON" pixel has
#define COLOROFF display.Color(47,79,79) // the color a "OFF" pixel has

/*______________________________________________________________________________________*/
/* Definitions that should not be changed */
#define NUMPIXELS 60    // number of neopixels in strip
#define WINDOWSIZE 10   // the size of the window (6 by X Pixel)

/*______________________________________________________________________________________*/
/* Create variables */
Adafruit_NeoPixel display = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte start = 0;           // at what index do we start displaying
byte finish = WINDOWSIZE; // at what index do we stop displaying
byte bMask=0;             // the byte mask to transport the data from the bitData[] to the actuall display
byte bStripIndex=0;       // the index of the led that gets currently writen to

//char originalInput[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','.',':','!','?'}; // enter the message you want to display this is every Posible char
char originalInput[]={'H','E','L','L','O','W','O','R','L','D'}; // enter the message you want to display

byte bitData[sizeof(originalInput)*5];  // in this array the actuall data will end up
                                        // the count of char's from the originalInput array times 7 because 6 for the letter and 1 space

/*______________________________________________________________________________________*/
/* Declare functions */
void vInitData();       // initialise the bitData array with the data from the originalInput array
void vPrintBin(byte i); // debug print statement
void vSetLed(byte index, bool state); // the led at pos x while be set to on or off

/*______________________________________________________________________________________*/
/* Implement functions */
void setup() {
  
  vInitData();
  display.begin();

  // debug code
  Serial.begin(9600);
  for(byte i=0;i<sizeof(originalInput)*7;i++){
    vPrintBin(bitData[i]);
  }
  // end debug code
}

void loop() {
// one loop is one refresh of the entire display
  bMask=1;        // starting in the first row
  bStripIndex=0;  // starting on the first led
  
  while(bStripIndex<NUMPIXELS){       // loop each led
    for(byte i=start;i<finish;i++){   // loop inside of row number X
      vSetLed(bStripIndex++, bitData[i] & bMask);
    }
    bMask = bMask << 1;               // shifting Mask to next row X+1
    for(int i=finish-1;i>=start;i--){ // loop inside of row number X+1
      vSetLed(bStripIndex++, bitData[i] & bMask);
    }
    bMask = bMask << 1;               // shifting Mask to next row X+2 or X for the next loop in while
  } 
  finish++;   //Shifting the window on space over
  start++;
  if(finish==sizeof(bitData)){
    start=0;
    finish=WINDOWSIZE;
  }
  
  display.show();
  delay(DELAY);
}

void vPrintBin(byte i){
  for (int8_t aBit = 7; aBit >= 0; aBit--){
    Serial.write(bitRead(i, aBit) ? '1' : '0');
  }
  Serial.write('\n');
}

void vSetLed(byte index, bool state){
  if(state){
    display.setPixelColor(index,COLORON);
  }else{
    display.setPixelColor(index,COLOROFF);
  }
}

void vInitData(){
  int dataIndex=0;
  for(int i=0;i<sizeof(originalInput);i++){
  
    switch(originalInput[i]){
      case 'A':
        bitData[dataIndex++]=0b111110;
        bitData[dataIndex++]=0b000101;
        bitData[dataIndex++]=0b000101;
        bitData[dataIndex++]=0b111110;
        break;
      case 'B':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b100101;
        bitData[dataIndex++]=0b100101;
        bitData[dataIndex++]=0b011010;
        break;
      case 'C':
        bitData[dataIndex++]=0b011110;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b100001;
        break;
      case 'D':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b011110;
        break;
      case 'E':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b100101;
        bitData[dataIndex++]=0b100101;
        bitData[dataIndex++]=0b100001;
        break;
      case 'F':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b001001;
        bitData[dataIndex++]=0b001001;
        bitData[dataIndex++]=0b000001;
        break;
      case 'G':
        bitData[dataIndex++]=0b011110;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b101001;
        bitData[dataIndex++]=0b111001;
        break;
      case 'H':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b000100;
        bitData[dataIndex++]=0b000100;
        bitData[dataIndex++]=0b111111;
        break;
      case 'I':
        bitData[dataIndex++]=0b111111;
        break;
      case 'J':
        bitData[dataIndex++]=0b010000;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b011111;
        break;
      case 'K':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b001000;
        bitData[dataIndex++]=0b010100;
        bitData[dataIndex++]=0b100011;
        break;
      case 'L':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b100000;
        break;
      case 'M':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b000010;
        bitData[dataIndex++]=0b000010;
        bitData[dataIndex++]=0b111111;
        break;
      case 'N':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b001000;
        bitData[dataIndex++]=0b010000;
        bitData[dataIndex++]=0b111111;
        break;
      case 'O':
        bitData[dataIndex++]=0b011110;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b011110;
        break;
      case 'P':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b001001;
        bitData[dataIndex++]=0b001001;
        bitData[dataIndex++]=0b000110;
        break;
      case 'Q':
        bitData[dataIndex++]=0b011110;
        bitData[dataIndex++]=0b100001;
        bitData[dataIndex++]=0b110001;
        bitData[dataIndex++]=0b111110;
        break;
      case 'R':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b001001;
        bitData[dataIndex++]=0b001001;
        bitData[dataIndex++]=0b110110;
        break;
      case 'S':
        bitData[dataIndex++]=0b100110;
        bitData[dataIndex++]=0b101001;
        bitData[dataIndex++]=0b101001;
        bitData[dataIndex++]=0b010001;
        break;
      case 'T':
        bitData[dataIndex++]=0b000001;
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b000001;
        break;
      case 'U':
        bitData[dataIndex++]=0b111111;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b111111;
        break;
      case 'V':
        bitData[dataIndex++]=0b011111;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b100000;
        bitData[dataIndex++]=0b011111;
        break;
      case 'W':
        bitData[dataIndex++]=0b011111;
        bitData[dataIndex++]=0b110000;
        bitData[dataIndex++]=0b110000;
        bitData[dataIndex++]=0b011111;
        break;
      case 'X':
        bitData[dataIndex++]=0b110011;
        bitData[dataIndex++]=0b001100;
        bitData[dataIndex++]=0b001100;
        bitData[dataIndex++]=0b110011;
        break;
      case 'Y':
        bitData[dataIndex++]=0b000111;
        bitData[dataIndex++]=0b111000;
        bitData[dataIndex++]=0b000111;
        break;
      case 'Z':
        bitData[dataIndex++]=0b110001;
        bitData[dataIndex++]=0b101001;
        bitData[dataIndex++]=0b100101;
        bitData[dataIndex++]=0b100011;
        break;
      case '.':
        bitData[dataIndex++]=0b100000;
        break;
      case ':':
        bitData[dataIndex++]=0b010010;
        break;
      case '!':
        bitData[dataIndex++]=0b101111;
        break;
      case '?':
        bitData[dataIndex++]=0b101001;
        bitData[dataIndex++]=0b000101;
        bitData[dataIndex++]=0b000010;
        break;      
      case ' ':
        bitData[dataIndex++]=0b000000;
        break;
    }
     bitData[dataIndex++]=0b000000;
  }
}
