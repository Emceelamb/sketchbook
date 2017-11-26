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

public class sketch_24 extends PApplet {

float t = 0.0f;
float[] seed = new float[16];
float[] speed = new float[16];

public void setup(){
    
    background(33);
    for(int i = 0; i<seed.length; i++){
        seed[i]=random(-width/2,width/2);
        print(seed[i]);
    }
    for(int i = 0; i<speed.length; i++){
        speed[i]=random(0,1);
    }
}

public void draw(){
    background(255);
    // map(value, low1, high1, low2, high2);
    t+=0.01f;
    translate(0,height/2);
    for(int i =0; i<16;i++){
        float x = map(noise(t+speed[i]),0,1,-width/2,width/2)+seed[i];
        float col = map(abs(x),0,width/2,255,0);
        // float col = map(abs(x),0,width/2,0,255);
        noStroke();
        fill(0,col);
        println(x);
        rect(i*40,0,40,x);
    }
    saveFrame("/out/#####.jpg");
}
  public void settings() {  size(640,640); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_24" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
