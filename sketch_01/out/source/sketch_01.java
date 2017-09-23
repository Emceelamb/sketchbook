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

public class sketch_01 extends PApplet {

float inc = 0;

public void setup(){
    

    ortho();
}
float rot = 0.f;
public void draw(){
    background(230);
    inc+=0.01f;
    pushMatrix();
    translate(width/2,height/2);
    rotateY(map(mouseX,0,width,0,PI));
    rotateZ(map(mouseY,0,height,0,PI));
    noFill();
    box(150);
    popMatrix();
}
 
  public void settings() {  size(600,600, OPENGL); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_01" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
