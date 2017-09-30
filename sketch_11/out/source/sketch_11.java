import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import shiffman.box2d.*; 
import org.jbox2d.collision.shapes.*; 
import org.jbox2d.common.*; 
import org.jbox2d.dynamics.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_11 extends PApplet {






Box2DProcessing box2d;		

ArrayList<Heart> hearts;
ArrayList<Edge> edges;
PShape heart;

public void setup() {
  

  box2d = new Box2DProcessing(this);	
  box2d.createWorld();  
  box2d.setGravity(0,-10);

  heart = loadShape("/data/heart.svg");
  heart.enableStyle();
  background(230);
  hearts = new ArrayList<Heart>();
  edges = new ArrayList<Edge>();
  edges.add(new Edge(0,height,width*2,10));
  edges.add(new Edge(0,0,10,height*2));
  edges.add(new Edge(width,0,10,height*2));
  
}

public void draw() {
  box2d.step();
  background(230);

  Vec2 worldPos = new Vec2(20,20);
  Vec2 pixelPos = box2d.coordWorldToPixels(worldPos);
  if (mousePressed) {
    Heart h = new Heart(random(width),0,20);
    hearts.add(h);
  }

  // Display all the boxes
  for (Heart h: hearts) {
    h.display();
  }

  for (Edge e : edges){
    e.display();
  }
}

// heart class object

class Heart{

  Body body;
  float r;

  Heart(float x, float y, float r_){
    r = r_;
    BodyDef bd = new BodyDef();
    bd.type = BodyType.DYNAMIC;
    bd.position.set(box2d.coordPixelsToWorld(x,y));

    CircleShape cs = new CircleShape();
    cs.m_radius = box2d.scalarPixelsToWorld(r);

    FixtureDef fd = new FixtureDef();
    fd.shape = cs;
    fd.density = 1;
    fd.friction = 0.3f;
    fd.restitution = 0.5f;
    body = box2d.createBody(bd);
    body.createFixture(fd);
  }

  public void display(){
    Vec2 pos = box2d.getBodyPixelCoord(body);
    float a = body.getAngle();

    ellipseMode(CENTER);
    pushMatrix();
    translate(pos.x,pos.y);
    rotate(-a);
    fill(175);
    stroke(255);
    // ellipse(0,0,r*2,r*2 );
    shape(heart, 0,0,r*2,r*2);
    line(0,0,r,r);
    popMatrix();
  }
  

}
// class Edge{
//   Body body;
//   float x,y,w,h;

//   Edge(float x_, float y_, float w_, float h_){
//     w = w_;
//     h = h_;
//     x = x_;
//     y = y_;

//     PolygonShape sd = new PolygonShape();
//     float box2dW = box2d.scalarPixelsToWorld(w/2);
//     float box2dH = box2d.scalarPixelsToWorld(h/2);
//     sd.setAsBox(box2dW, box2dH);
//     // FixtureDef fd = new FixtureDef();
//     // fd.shape = sd;
//     // fd.density = 1;
//     // fd.friction = 0.3;
//     BodyDef bd = new BodyDef();
//     bd.type = BodyType.STATIC;
//     bd.position.set(box2d.coordPixelsToWorld(x,y));
//     body = box2d.createBody(bd);
//     body.createFixture(sd,1);
//   }

//   void display(){
//     rectMode(CENTER);
//     rect(x,y,w,h);

//   }
// }


class Edge {

  // A boundary is a simple rectangle with x,y,width,and height
  float x;
  float y;
  float w;
  float h;
  
  // But we also have to make a body for box2d to know about it
  Body b;

  Edge(float x_,float y_, float w_, float h_) {
    x = x_;
    y = y_;
    w = w_;
    h = h_;

    // Define the polygon
    PolygonShape sd = new PolygonShape();
    // Figure out the box2d coordinates
    float box2dW = box2d.scalarPixelsToWorld(w);
    float box2dH = box2d.scalarPixelsToWorld(h);
    // We're just a box
    sd.setAsBox(box2dW, box2dH);


    // Create the body
    BodyDef bd = new BodyDef();
    bd.type = BodyType.STATIC;
    bd.position.set(box2d.coordPixelsToWorld(x,y));
    b = box2d.createBody(bd);
    
    // Attached the shape to the body using a Fixture
    b.createFixture(sd,1);
  }

  // Draw the boundary, if it were at an angle we'd have to do something fancier
  public void display() {
    fill(0);
    stroke(0);
    rectMode(CENTER);
    rect(x,y,w,h);
  }

}
  public void settings() {  size(640, 640); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_11" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
