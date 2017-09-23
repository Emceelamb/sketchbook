import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.video.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_02 extends PApplet {


PGraphics pg;
Capture cam;
float rotx = 0;
float roty = 0;

public void setup() {
    
    textureMode(NORMAL);
    fill(255);
    stroke(color(44,48,32));
    cam = new Capture(this, 640,480);
    cam.start();
    pg = createGraphics(640,640,OPENGL);
    ortho();
}

public void draw() {
    // image(cam,0,0);
    pg.beginDraw();
    pg.background(230);
    // pg.pushMatrix();
    // pg.imageMode(CENTER);
    pg.image(cam,0,0,700,700);
    // pg.popMatrix();
    pg.endDraw();

    background(0);
    noStroke();
    translate(300,300);
    for(int i = 0; i <3; i++){
        for(int j = 0; j <3; j++){

        pushMatrix();

        translate(i*300, j*300, -100);
        rotateX(rotx);
        rotateZ
        (roty);
        scale(90);
        TexturedCube(pg);
        popMatrix();
        }
    }

    rotx+=0.01f;
    roty+=0.01f;
}

public void captureEvent(Capture c){
    c.read();

}

public void TexturedCube(PGraphics pg) {
  beginShape(QUADS);
  texture(pg);

  vertex(-1, -1,  1, 0, 0);
  vertex( 1, -1,  1, 1, 0);
  vertex( 1,  1,  1, 1, 1);
  vertex(-1,  1,  1, 0, 1);

  // -Z "back" face
  vertex( 1, -1, -1, 0, 0);
  vertex(-1, -1, -1, 1, 0);
  vertex(-1,  1, -1, 1, 1);
  vertex( 1,  1, -1, 0, 1);

  // +Y "bottom" face
  vertex(-1,  1,  1, 0, 0);
  vertex( 1,  1,  1, 1, 0);
  vertex( 1,  1, -1, 1, 1);
  vertex(-1,  1, -1, 0, 1);

  // -Y "top" face
  vertex(-1, -1, -1, 0, 0);
  vertex( 1, -1, -1, 1, 0);
  vertex( 1, -1,  1, 1, 1);
  vertex(-1, -1,  1, 0, 1);

  // +X "right" face
  vertex( 1, -1,  1, 0, 0);
  vertex( 1, -1, -1, 1, 0);
  vertex( 1,  1, -1, 1, 1);
  vertex( 1,  1,  1, 0, 1);

  // -X "left" face
  vertex(-1, -1, -1, 0, 0);
  vertex(-1, -1,  1, 1, 0);
  vertex(-1,  1,  1, 1, 1);
  vertex(-1,  1, -1, 0, 1);

  endShape();
}

// void mouseDragged() {
//   float rate = 0.01;
//   rotx += (pmouseY-mouseY) * rate;
//   roty += (mouseX-pmouseX) * rate;
// }
  public void settings() {  size(1280, 1280, P3D); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_02" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
