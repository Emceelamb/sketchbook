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

public class sketch_03 extends PApplet {

PGraphics pg;
int c;
float t;
float a = 0.0f;
public void setup(){
    
    pg = createGraphics(600,600);
    c = color(33,30);
    frameRate(120);
}

public void draw(){
    // if(filled()){
    //     c = color(233,30);
    // } else {
    //     c = color(33,30);
    // }
    
    pg.beginDraw();
    pg.stroke(c);
    pg.strokeWeight(5);
    pg.noFill();
    pg.ellipse(x(t), y(t),60,60);
    pg.endDraw();
    
    translate(width/2,height/2);
    rotate(t);
    image(pg,0,0);
    t+=5;
    a+=1;
    println(a);
    if(a>400){
        a = 0;
        c = color(random(233),random(233),random(233),30);

    }

    saveFrame("../images/spiral/spiral_#####.jpg");
}



public boolean filled(){
    if(a>400){
        return true;
    } else {
        return false;
    }
}

public float x(float t){
    return sin(t*10+t*5) * a;
 
}

public float y(float t){
    return cos(t*10+t*5) * a;
}
  public void settings() {  size(600,600); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_03" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
