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

public class sketch_10 extends PApplet {






Particle[] particles = new Particle[10];
Edge[] edges = new Edge[3];
Box2DProcessing box2d;		
public void setup() {
  

  box2d = new Box2DProcessing(this);	
  box2d.createWorld();  
  box2d.setGravity(0,-10);

  background(230);
  for (int i = 0; i <particles.length; i++) {
    particles[i] = new Particle(10,10);
  }
  edges[0]= new Edge(0,0,10,height);
  edges[1]= new Edge(0,height,width,40);

  edges[2]= new Edge(width,0,10,height);


}

public void draw() {
  box2d.step();
  background(230);

  Vec2 worldPos = new Vec2(20,20);
  Vec2 pixelPos = box2d.coordWorldToPixels(worldPos);
  
  for (Particle p : particles) {
    p.checkEdges();
    // p.collision();
    p.update();
    p.display();
  }

  for(Edge e : edges){
    e.display();
  }
  edges[1].display();
  
  fill(255,0,0);
  ellipse(pixelPos.x,pixelPos.y,16,16);
}
class Edge {

  // PVector location;
  float w,h;
  Body body;
  Vec2 pos;

  Edge(float x, float y, float w_, float h_) {
    w = w_;
    h = h_;
    BodyDef bd = new BodyDef();
    bd.type = BodyType.STATIC;
    bd.position.set(box2d.coordPixelsToWorld(x,y));
    body = box2d.createBody(bd);

    PolygonShape ps = new PolygonShape();
    float box2dW = box2d.scalarPixelsToWorld(w);
    float box2dH = box2d.scalarPixelsToWorld(h);

    ps.setAsBox(box2dW, box2dH);

    FixtureDef fd = new FixtureDef();
    fd.shape = ps;
    body.createFixture(fd);
  }
    
  public void display() {
    Vec2 pos = box2d.getBodyPixelCoord(body);
    pushMatrix();
    translate(pos.x,pos.y);
    fill(255,0,255);
    strokeWeight(5);
    rect(0,0,w,h);
    println(pos.x);
    popMatrix();

   }
}
class Particle {

  // PVector location;
  float w,h;
  Body body;
  float angle;
  Vec2 pos;

  Particle(float x, float y) {
  // Particle(PVector location_, PVector velocity_,int r_) {
    w=random(15,25); 
    h=random(10,25);
    BodyDef bd = new BodyDef();
    bd.type = BodyType.DYNAMIC;
    // PVector velocity;
    // location = new PVector(location_.x, location_.y);
    // velocity = new PVector(velocity_.x, velocity_.y);
    // r = r_;
    // Vec2 center = box2d.coordPixelsToWorld(width/2,height2));
    bd.position.set(box2d.coordPixelsToWorld(width/2,height/2));
    bd.linearDamping = 0.8f;
    bd.angularDamping = 0.9f;
    body = box2d.createBody(bd);

    PolygonShape ps = new PolygonShape();
    float box2dW = box2d.scalarPixelsToWorld(w/2);
    float box2dH = box2d.scalarPixelsToWorld(h/2);

    ps.setAsBox(box2dW, box2dH);

    FixtureDef fd = new FixtureDef();
    fd.shape = ps;
    fd.density = random(2,4);
    fd.friction = 0.3f;
    fd.restitution =0.5f;
    body.createFixture(fd);
  }
  
  
  public void update() {
    // body.setLinearVelocity(new Vec2(0,3));
    // body.setAngularVelocity(1,2);
  }

  public void checkEdges() {
    // if (pos.x>width||pos.x<0) {
    //   velocity.x*=-1;
    // }
    // if (pos.y>height||pos.y<0) {
    //   velocity.y*=-1;
    // }
    
    
  }
  
  // void collision(){
  // for (int i = 0; i<particles.length-1; i++) {
  // Particle p1 = particles[i];
  //   for (int j = i+1; j<particles.length; j++) {
  //     Particle p2  = particles[j];
  //     float dx = p2.location.x - p1.location.x;
  //     float dy = p2.location.y - p1.location.y;
  //     float d = sqrt(sq(dx)+sq(dy)); // distance between balls
  //     if (d < p1.r/2+p2.r/2) {
  //       float angle = PVector.angleBetween(p1.location,p2.location);
  //       // println(angle);
  //       angle = map(angle,0,0.4
  //       ,0,PI);
  //       pushMatrix();
  //       rotate(angle);
  //       popMatrix();
  //       p1.velocity.mult(-1);
  //       p2.velocity.mult(-1);
  //       fill(random(255),random(255),random(255));
  //       println("collided!");
  //     } 
  //   }
  // }
  // }
  
  public void display() {
    Vec2 pos = box2d.getBodyPixelCoord(body);
    float angle = body.getAngle();
    pushMatrix();
    translate(pos.x, pos.y);
    rotate(-angle);

    fill(33);
    noStroke();
    rect(0,0,w,h);
    popMatrix();

    // ellipse(location.x, location.y, r*2, r);
  }
}
  public void settings() {  size(640, 640); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_10" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
