import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import ddf.minim.*; 
import ddf.minim.analysis.*; 
import ddf.minim.effects.*; 
import ddf.minim.signals.*; 
import ddf.minim.spi.*; 
import ddf.minim.ugens.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_04 extends PApplet {








int total = 100;
ArrayList<Particle> ps= new ArrayList<Particle>();

Minim minim;
AudioPlayer hello;

float grav;

public void setup() {
    
    for (int i = 0; i < total; i++) {
        ps.add(new Particle());
  }
    minim = new Minim(this);
    hello = minim.loadFile("/data/hello.mp3", 1024);
    hello.loop();

}

public void draw() {
    background(0xffADD8E6);

    for(int i  = 0; i < hello.bufferSize() -1; i++){
        grav = map(hello.left.get(i),-1,1,-8,8);
    }

    println(grav);

    PVector wind = new PVector(0.2f, 0);
    PVector gravity = new PVector(0, grav);
    for (int i = 0; i < ps.size(); i ++) {
        Particle p = ps.get(i);
    if (mousePressed) {
        p.applyForce(wind);
    }
    p.applyForce(gravity);
    p.update();
    p.checkEdges();
    //p.collision();
    p.display();
    if (p.dead()) {
      ps.remove(i);
    }
  }

  //ps.add(new Particle());
}

class Particle {
  PVector location;
  PVector velocity;
  PVector acceleration;
  float mass;
  float radius;

  int lifespan = 255;

  Particle() {
    location = new PVector(random(width), height/2);
    acceleration = new PVector(0, 0);
    velocity = new PVector(0, 0);
    radius = random(20, 40);
    mass = random(5, 12);
  }

  public void applyForce(PVector force) {
    PVector f = PVector.div(force, mass);
    acceleration.add(f);
  }

  public void update() {
    velocity.add(acceleration);
    location.add(velocity);
    //lifespan-=2;

    acceleration.mult(0);
  }

  public void checkEdges() {
    if (location.x>width || location.x<0) {
      velocity.x*=-1;
    }
    if (location.y>width || location.y<0) {
      velocity.y*=-1;
    }
  }

  public void display() {
    stroke(0xffADD8E6, lifespan);
    fill(255, lifespan);
    ellipse(location.x, location.y, mass*10, mass*10);
  }

  public boolean dead() {
    if (lifespan<0) {
      return true;
    } else {
      return false;
    }
  }

}
  public void settings() {  size (800, 800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_04" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
