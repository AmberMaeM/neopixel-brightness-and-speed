#include <Adafruit_NeoPixel.h>

#define N_PIXELS 84 // Number of pixels you are using
#define LED_PIN     6 // NeoPixel LED strand is connected to GPIO #0 / D0
Adafruit_NeoPixel  pixels = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int sensorValue = 0;
int outputValue = 0;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int val =0;
//0=minimum possible for potval variable
int speed = map(val,0,1023,10,300);
//speed,brightness = variable that will get the new number
//1023 = maximum possible for val variable
//10,0 = new lowest value
//300,255 = new hightest value.
int potPin = A0; //pin the potentiometer is in


void setup() {
  pixels.begin();
pinMode(A0,INPUT);// sets the A0 pin as an input
  pixels.setBrightness(outputValue); // Set LED brightness 0-255
  
  pixels.show(); // Update pixels
}

void loop() {
 setColor();
sensorValue = analogRead(A1);//potentiometer is in A1, also is an input
outputValue = map(sensorValue, 0, 1023, 0, 255); 
//0 are the lowest it can go
//1023 is the highest for the potentiometer
//255 is the highest value for the lights
 for(int i=0;i<N_PIXELS;i++){
 val = analogRead(potPin);    // read the value from the potentiometer
  pixels.setBrightness(outputValue);
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); 

    pixels.show(); // update pixels
delay(val);
   
    
   Serial.println(i);
    
    if (i == N_PIXELS){
      i = 0; // start all over again!
        setColor();
    }

  }
}
// Fill the dots one after the other with a color

void setColor(){
  redColor = random(0, 255); // sets the colour to random reds
  greenColor = random(0,255);// sets the colour to random greens
  blueColor = random(0, 255);//sets the colour to random blues
  // goes on serial monitor
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
  
}
