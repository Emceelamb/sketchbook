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

public class sketch_47 extends PApplet {

float t = 0.0f;
float[] seed = new float[16];
float[] speed = new float[16];
float[] hght = new float[16];

public void setup(){
    
    background(33);
    for(int i = 0; i<seed.length; i++){
        seed[i]=random(-width/2,width/2);
        print(seed[i]);
    }
    for(int i = 0; i<speed.length; i++){
        speed[i]=1;
    }
    for(int i = 0; i<hght.length; i++){
        hght[i]=1*seed[i];
    }

}

public void draw(){
    background(186,225,255);
    // map(value, low1, high1, low2, high2);
    t+=0.01f;
    translate(0,height);
    for(int i =0; i<16;i++){
        float x = map(noise(t+speed[i]),0,1,-width/2,width/2)+seed[i];
        float col = map(abs(x)*0.25f,0,width/2,200,50);
        float h = noise(t+hght[i])*200;
        // float col = map(abs(x),0,width/2,0,255);
        noStroke();
        fill(30,30,80,col);
        println(x);
        // ellipse(i*40,h-40,40,40);
        for(int j = 0; j<30; j++){
            rect((i*40)+(20*i),h-(40*j)+(20*i),40,40);
        }
    }
    // saveFrame("/out1/#####.jpg");
}
  public void settings() {  size(640,640); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_47" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
