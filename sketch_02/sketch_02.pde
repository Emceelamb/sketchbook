import processing.video.*;
PGraphics pg;
Capture cam;
float rotx = 0;
float roty = 0;

void setup() {
    size(1280, 1280, P3D);
    textureMode(NORMAL);
    fill(255);
    stroke(color(44,48,32));
    cam = new Capture(this, 640,480);
    cam.start();
    pg = createGraphics(640,640,OPENGL);
    ortho();
}

void draw() {
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

    rotx+=0.01;
    roty+=0.01;
}

void captureEvent(Capture c){
    c.read();

}

void TexturedCube(PGraphics pg) {
  beginShape(QUADS);
  texture(pg);
  vertex(-1, -1,  1, 0 );
  vertex(-1, -1,  1, 0 );
  vertex( 1, -1,  1, 1 );
  vertex( 1,  1,  1, 1 );
  vertex(-1,  1,  1, 0 );
  // -Z "back" fa
  vertex( 1, -1, -1, 0 );
  vertex(-1, -1, -1, 1 );
  vertex(-1,  1, -1, 1 );
  vertex( 1,  1, -1, 0 );
  // +Y "bottom" fa
  vertex(-1,  1,  1, 0 );
  vertex( 1,  1,  1, 1 );
  vertex( 1,  1, -1, 1 );
  vertex(-1,  1, -1, 0 );
  // -Y "top" fa
  vertex(-1, -1, -1, 0 );
  vertex( 1, -1, -1, 1 );
  vertex( 1, -1,  1, 1 );
  vertex(-1, -1,  1, 0 );
  // +X "right" fa
  vertex( 1, -1,  1, 0 );
  vertex( 1, -1, -1, 1 );
  vertex( 1,  1, -1, 1 );
  vertex( 1,  1,  1, 0 );
  // -X "left" fa
  vertex(-1, -1, -1, 0 );
  vertex(-1, -1,  1, 1 );
  vertex(-1,  1,  1, 1 );
  vertex(-1,  1, -1, 0 );
  endShape();

}
// void mouseDragged() {
//   float rate = 0.01;
//   rotx += (pmouseY-mouseY) * rate;
//   roty += (mouseX-pmouseX) * rate;
// }