#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

#define rxPin 0 //define rx data pin
#define txPin 1 //define tx data pin
#define PIN 6   //LED pin

// Declare the pins for the Button and the LED
const int buttonPin = 12;
const int LED = 13;
const int brightness = 10;
char commandChar;

//create instance of SoftwareSerial
SoftwareSerial bluetooth(rxPin, txPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(240, PIN, NEO_GRB + NEO_KHZ800);

uint32_t PINK =   strip.Color(255, 50, 80);
uint32_t RED =    strip.Color(255, 0, 0);
uint32_t ORANGE = strip.Color(255, 10, 0);
uint32_t YELLOW = strip.Color(255, 255, 0);
uint32_t GREEN =  strip.Color(0, 255, 0);
uint32_t BLUE =   strip.Color(0, 0, 255);
uint32_t PURPLE = strip.Color(255, 0, 255);

uint32_t OFF = strip.Color(0, 0, 0);
char inData[64]; //Space for storing message

void setup() {

   strip.begin();
   strip.setBrightness(255);
   //Initialize all pixels to 'off'
   strip.show();
   
   // Define pin #12 as input and activate the internal pull-up resistor
   pinMode(buttonPin, INPUT_PULLUP);
   // Define pin #13 as output, for the LED
   pinMode(LED, OUTPUT);

   pinMode(rxPin, INPUT);
   pinMode(txPin, OUTPUT);

   //Setup usb serial connection to computer
   Serial.begin(9600);    //Start hardware Serial

   //Setupt Bluetooth serial connection to android
   bluetooth.begin(9600); //Start software Serial
}

void loop(){

      //rainbow(10);
      rainbow(10);
      //theaterChaseRainbow(50);

    

    if(bluetooth.available()>0){
      char inChar;
      inChar = bluetooth.read(); //Read a char
      play(inChar);
    }
    
    
   /*
   // Read the value of the input. It can either be 1 or 0
   int buttonValue = digitalRead(buttonPin);
   if (buttonValue == HIGH){ //Button Pressed
      // If button pushed, turn LED on
      digitalWrite(LED,HIGH);
      
      if(bluetooth.available()){
        Serial.print("Hardware Pressed#");
      }
      
    } else { //Button not pressed.
     */
        //Turn off LED
        //byte index = 0;
        /*
        if(bluetooth.available() > 0){
          char inChar;
          if(index < 63){
            inChar = bluetooth.read(); //Read a char
            inData[index] = inChar; //Store char in inData string
            index++;
            if(index == 63){
              inData[index] = '#'; //Null terminate the string
            }
          }
          if (index < 63)
          {
            inData[index] = '#';
          }
          for(int i = 0; i < 64; i++)
          {
            Serial.print(inData[i]);
          }
          Serial.print("#");
          colorWipe(GREEN,1);
          delay(2000);
          */

            /*
          for(byte i = 0; i < 2; i++){
            switch (inChar){
              case '*':
                //Serial.print("You sent a star!\n#");

                break;
              case 'm':
               // Serial.print("You sent an m!\n#");
                //colorWipe(RED,10);

                break;
              default:
              
                Serial.print("You sent a ... ");
                Serial.print(inData[i]);
                Serial.print("\n#");
                clearStrip();
                delay(1000);
               
                break;
            }
          }
          */
        digitalWrite(LED, LOW);
  }

void play(char c){
  switch (c){
    case 'a':
      colorWipeDown(PINK,25);
      break;
    case 'b':
      colorWipe(PINK,25);
      break;
    case 'c':
      fadeOn(PINK);
      break;
    case 'd':
      fadeOff(PINK);
      break;
    case 'e':
      flash(PINK);
      break;
    case 'A':
      colorWipeDown(RED,25);
      break;
    case 'B':
      colorWipe(RED,25);
      break;
    case 'C':
      fadeOn(RED);
      break;
    case 'D':
      fadeOff(RED);
      break;
    case 'E':
      flash(RED);
      break;
    case 'f':
      colorWipeDown(ORANGE,25);
      break;
    case 'g':
      colorWipe(ORANGE,25);
      break;
    case 'h':
      fadeOn(ORANGE);
      break;
    case 'i':
      fadeOff(ORANGE);
      break;
    case 'j':
      flash(ORANGE);
      break;
    case 'F':
      colorWipeDown(YELLOW,25);
      break;
    case 'G':
      colorWipe(YELLOW,25);
      break;
    case 'H':
      fadeOn(YELLOW);
      break;
    case 'I':
      fadeOff(YELLOW);
      break;
    case 'J':
      flash(YELLOW);
      break;
    case 'k':
      colorWipeDown(GREEN,25);
      break;
    case 'l':
      colorWipe(GREEN,25);
      break;
    case 'm':
      fadeOn(GREEN);
      break;
    case 'n':
      fadeOff(GREEN);
      break;
    case 'o':
      flash(GREEN);
      break;
    case 'K':
      colorWipeDown(BLUE,25);
      break;
    case 'L':
      colorWipe(BLUE,25);
      break;
    case 'M':
      fadeOn(BLUE);
      break;
    case 'N':
      fadeOff(BLUE);
      break;
    case 'O':
      flash(BLUE);
      break;
    case 'p':
      colorWipeDown(PURPLE,25);
      break;
    case 'q':
      colorWipe(PURPLE,25);
      break;
    case 'r':
      fadeOn(PURPLE);
      break;
    case 's':
      fadeOff(PURPLE);
      break;
    case 't':
      flash(PURPLE);
      break;
     case 'x':
     rainbow(10);
      rainbow(10);
      rainbow(10);
      //rainbowCycle(10);
      theaterChaseRainbow(10);
      theaterChaseRainbow(50);
      theaterChaseRainbow(100);
      
      break;
  }
}

void clearStrip(){
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, OFF);
  }
  strip.show();
}

void flash(uint32_t c) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    //strip.show();
  }
  for(uint16_t i = 0; i < 10; i++) {
    strip.setBrightness(255);
    strip.show();
    i++;
    delay(500);
    strip.setBrightness(1);
    strip.show();
    delay(500);
  }
  strip.setBrightness(255);
}

void fadeOff(uint32_t c) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,c);
  }
  for(uint16_t i = 255; i > 0; i--){
    strip.setBrightness(i);
    strip.show();
    delay(20);
  }
}

void fadeOn(uint32_t c) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,c);
  }
  for(uint16_t i = 1; i < 255; i++){
    strip.setBrightness(i);
    strip.show();
    delay(20);
  }
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  clearStrip();
  strip.setBrightness(255);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipeDown(uint32_t c, uint8_t wait) {
   clearStrip();
   strip.setBrightness(255);
  for(uint16_t i = strip.numPixels()-1; i > 0; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  strip.setBrightness(255);

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
    strip.setBrightness(255);

  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
