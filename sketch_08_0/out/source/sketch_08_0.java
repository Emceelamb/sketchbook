import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_08_0 extends PApplet {

PImage img; 
PImage sorted;
int sw = 1383;
int sh = 2048;

public void setup(){
    
    img = loadImage("/data/heads.jpg");
    sorted = createImage(img.width, img.height, RGB);
    img.loadPixels();
    // for(int i = 0; i<img.pixels.length; i++){
    //     sorted.pixels[i] = img.pixels[i];
    // }
    sorted = img.get();
    sorted.loadPixels();
}
int sample_size = PApplet.parseInt(random(20,80));
public void draw(){
    
    // image(img,0,0);

    float x = random(width);
    float y = random(height);
    int c = img.get(PApplet.parseInt(x), PApplet.parseInt(y));
    fill(c);
    noStroke();
    rect(x,y,60,60);

}
  public void settings() {  size (1383, 2048); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_08_0" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
