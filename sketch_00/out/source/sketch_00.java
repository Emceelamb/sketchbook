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

public class sketch_00 extends PApplet {

Spinner[][] spinners  = new Spinner[120][120];

public void setup(){
    
    ortho();
    for(int i = 0; i<spinners.length; i++){
        for(int j = 0; j <spinners[1].length; j++){
            spinners[i][j] = new Spinner(36.0f);
        }
    }
}
float rot = 0.f;
public void draw(){
    background(230);
    // pushMatrix();
    // translate(width/2,height/2,-500);
    // rectMode(CENTER);
    // rotateZ(rot);
    // rotateY(rot);
    // rect(0,0,400,400);
    // popMatrix();
    rot-=0.1f;
    for(int i = 0; i < spinners.length; i++){
        for(int j = 0; j <spinners[1].length; j++){
            pushMatrix();
            translate(i*spinners[0][0].rad,j*spinners[0][0].rad);
            spinners[i][j].update();
            spinners[i][j].display();
            popMatrix();
        }
    }

    
}

class Spinner{
    float x,y,z;
    float rad;
    Spinner(float rad_){
        x = 0;
        y = 0;
        z = 0;
        rad = rad_;

    }
    public void update(){
        y += 0.05f;
        z += 0.05f;
    }

    public void display(){
        pushMatrix();
        rotateY(y);
        rotateZ(z);
        noFill();
        // strokeWeight(5);
        stroke(33);
        // fill(#7eb09b);
        rectMode(CENTER);
        rect(0, 0, rad, rad);
        popMatrix();
    }
}
  public void settings() {  size(600,600, OPENGL); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_00" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
