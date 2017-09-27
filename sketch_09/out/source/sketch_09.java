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

public class sketch_09 extends PApplet {

float t;
PImage img;
public void setup(){
    
    img = loadImage("/data/heads.jpg");
    img.loadPixels();
}

public void draw(){
    background(233);
    
    for(int i = 1; i < 130; i++){
        for(int j = 1; j < 200; j++){
            float x_ = x(t)+10*i;
            float y_ = y(t)+10*j;
            int c = img.get(PApplet.parseInt(x_),PApplet.parseInt(y_));
            strokeWeight(map(brightness(c),0,255,8,4));
            stroke(c);
            pushMatrix();
            // translate(10*i,10*j);
            point(x_,y_);
            popMatrix();
        }
    }   

    t++;
}

public float x(float t){
    return sin(t/10)*10;
}


public float y(float t){
    return cos(t/10)*10;
}
  public void settings() {  size(1383,2048); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_09" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
