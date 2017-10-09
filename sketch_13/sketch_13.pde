// This sketch shows how to use the FFT class to analyze a stream  
// of sound. Change the variable bands to get more or less 
// spectral bands to work with. Smooth_factor determines how
// much the signal will be smoothed on a scale form 0-1.

import processing.sound.*;

// Declare the processing sound variables 
SoundFile sample;
Amplitude amp;
// AudioDevice device;

float sum;
// Create a smoothing factor
float smooth_factor = 0.1;

PShape heart;

public void setup() {
  size(640, 640);
  background(255);
  
  
  sample = new SoundFile(this, "heart.mp3");
  sample.loop();
  amp = new Amplitude(this);

  amp.input(sample);
  
  heart = loadShape("/data/heart1.svg");
}      
float am;
public void draw() {
  // Set background color, noStroke and fill color
  background(233);
  sum+=(amp.analyze() - sum)*smooth_factor;
  am = map(sum, 0,0.1,0.50,3.0);
 
  if(am<1.15){

    for(int x = 0; x<3;x++){
      for(int y = 0; y<3; y++){
        pushMatrix();
        translate(200,200);
        shapeMode(CENTER);
        shape(heart, x*120,y*120, am*100,am*100);
        popMatrix();
      }
    }
  } else {
      translate(width/2,height/2);
      shape(heart,0,0,am*100,am*100);
  }
}