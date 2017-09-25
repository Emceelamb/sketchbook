import gab.opencv.*;
import processing.video.*;
import java.awt.*;

PGraphics pg;
Capture cam;
float rotx = 0;
float roty = 0;

OpenCV opencv;
PGraphics boxhead;

void setup() {
    size(1280, 960, P3D);
    textureMode(NORMAL);
    fill(255);
    stroke(color(44,48,32));
    cam = new Capture(this, 640/2,480/2);
    cam.start();
    //pg = createGraphics(640,640,OPENGL);
    opencv = new OpenCV(this, 640/2, 480/2);
    opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);  
    ortho();
}

void draw() {
    scale(4);
    opencv.loadImage(cam);
    image(cam,0,0);
    
    Rectangle[] faces = opencv.detect();
    for(int i =0; i< faces.length; i++){
      
    
    pg = createGraphics(faces[i].width,faces[i].height,OPENGL);
  
    // image(cam,0,0);
    pg.beginDraw();
    pg.background(230);
    // pg.pushMatrix();
    // pg.imageMode(CENTER);
    pg.copy(cam,faces[i].x,faces[i].y,faces[i].width,faces[i].height,0,0,faces[i].width,faces[i].height);
    // pg.popMatrix();
    pg.endDraw();
    
    //image(pg,faces[i].x,faces[i].y);
    
    

    
    noStroke();
    translate(faces[i].x+faces[i].width/2,faces[i].y+faces[i].height/2,100);


        pushMatrix();

        rotateX(-90);
        rotateY(roty);
        scale(faces[i].width/2);
        TexturedCube(pg);
        popMatrix();
        }
    
    
    //rotx+=0.11;
    roty+=0.1;
}

void captureEvent(Capture c){
    c.read();

}

void TexturedCube(PGraphics pg) {
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