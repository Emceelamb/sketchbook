import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import ddf.minim.analysis.*; 
import ddf.minim.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_06 extends PApplet {




Minim       minim;
AudioPlayer jingle;
FFT         fft;

public void setup()
{
  
  
  minim = new Minim(this);
  
  // specify that we want the audio buffers of the AudioPlayer
  // to be 1024 samples long because our FFT needs to have 
  // a power-of-two buffer size and this is a good size.
  jingle = minim.loadFile("data/hello.mp3", 1024);
  
  // loop the file indefinitely
  jingle.loop();
  
  // create an FFT object that has a time-domain buffer 
  // the same size as jingle's sample buffer
  // note that this needs to be a power of two 
  // and that it means the size of the spectrum will be half as large.
  fft = new FFT( jingle.bufferSize(), jingle.sampleRate() );
  
}

public void draw()
{
  background(0);
  stroke(255);
  
  // perform a forward FFT on the samples in jingle's mix buffer,
  // which contains the mix of both the left and right channels of the file
  fft.forward( jingle.mix );
  
  for(int i = 0; i < fft.specSize(); i++)
  {
    // draw the line for frequency band i, scaling it up a bit so we can see it
    line( i, height, i, height - fft.getBand(i)*32 );
  }
}
  public void settings() {  size(512, 600, P3D); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_06" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
