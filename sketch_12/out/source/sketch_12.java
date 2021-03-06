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

public class sketch_12 extends PApplet {

float space = 10;
int it;
float rot;
public void setup(){
    
    background(33);
    frameRate(8);
}

public void draw(){
    stroke(233);
    int c = PApplet.parseInt(random(255));
    pushMatrix();
    translate(0,it*20);
    noStroke();
    fill(33);
    rect(0,0,width,20);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int j = 0; j < 40; j++){
        pushMatrix();
        translate(j*20, 20*it);
        if(random(1)<0.5f){
            line(0,0,20,20); 
        } else {   
            line(0,20,20,0);
        }
        popMatrix();
    }
    pushMatrix();
    translate(0,(height-it*20));
    noStroke();
    fill(33);
    rect(0,0,width,20);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int j = 0; j < 40; j++){
        pushMatrix();
        translate(j*20, (height-20*it));
        if(random(1)<0.5f){
            line(0,0,20,0); 
        } else {   
            line(0,20,0,0);
        }
        popMatrix();
    }

    //  r to l

    pushMatrix();
    translate((width-it*20),0);
    noStroke();
    fill(33);
    rect(0,0,20,height);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int i = 0; i < 100; i++){
        pushMatrix();
        translate((width-20*it), 20*i);
        if(random(1)<0.5f){
            line(0,0,20,20); 
        } else {   
            line(0,20,20,0);
        }
        popMatrix();
    }

    // l to r
    pushMatrix();
    translate(it*20,0);
    noStroke();
    fill(33);
    rect(0,0,20,height);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int i = 0; i < 100; i++){
        pushMatrix();
        translate(20*it, 20*i);
        if(random(1)<0.5f){
            line(0,0,20,0); 
        } else {   
            line(0,20,0,0);
        }
        popMatrix();
    }


    //
    
    it++;
    if(it>30){
        it=0;
        // background(33);
    }
    rot+=0.001f;

    saveFrame("../images/goto10/goto_####.jpg");
}
  public void settings() {  size(600,600); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_12" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
