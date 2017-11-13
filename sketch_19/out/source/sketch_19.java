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

public class sketch_19 extends PApplet {

float t;

public void setup(){
    
    background(33);
    t =0.0f;
}

public void draw(){

    
    
    noStroke();
    translate(50,50);
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10;j++){

            float c = map(noise(t)*j*i,0,10,0,233);
            fill(c);
            ellipseMode(CENTER);
            ellipse(60*i,60*j,40,40);
        }
    }
    
    t+=0.01f;
}

  public void settings() {  size(640,640); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_19" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
