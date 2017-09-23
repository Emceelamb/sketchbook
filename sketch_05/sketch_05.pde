// particles sketch


int total = 100;
int max_distance = 80;
ArrayList<Particle> ps= new ArrayList<Particle>();

Repel repel;


void setup() {
    size (800, 800);
    for (int i = 0; i < total; i++) {
        ps.add(new Particle());
  }

  repel = new Repel(); 

}

void draw() {
    background(#ADD8E6);

    PVector wind = new PVector(0.2, 0);
    PVector gravity = new PVector(0, 0);
    for (int i = 0; i < ps.size(); i ++) {
        Particle p = ps.get(i);
        PVector f = repel.repel(p, new PVector(mouseX,mouseY));
    if (mousePressed) {
        p.applyForce(wind);
    }
    // p.applyForce(gravity);
    p.applyForce(f);
    p.update();
    p.checkEdges();
    //p.collision();
    p.display();
    if (p.dead()) {
      ps.remove(i);
    }

    for(int j =1; j<ps.size()-1;j++){
        
    Particle p1 = ps.get(j);
    // println(p1);
    float distance = dist(p.location.x,p.location.y,p1.location.x,p1.location.y);
    if(distance<=max_distance){
        stroke(255);
        strokeWeight(1-distance/max_distance);
        line(p.location.x,p.location.y, p1.location.x,p1.location.y);
        }
    }

  }
    repel.display();
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
    location = new PVector(random(width), random(height));
    acceleration = new PVector(0, 0);
    velocity = new PVector(random(3), random(3));
    radius = random(20, 40);
    mass = 1;
  }

  void applyForce(PVector force) {
    PVector f = PVector.div(force, mass);
    acceleration.add(f);
  }

  void update() {
    velocity.add(acceleration);
    location.add(velocity);
    //lifespan-=2;

    acceleration.mult(0);
  }

  void checkEdges() {
    if (location.x>width || location.x<0) {
      velocity.x*=-1;
    }
    if (location.y>width || location.y<0) {
      velocity.y*=-1;
    }
  }

  

  void display() {
    stroke(#ADD8E6, lifespan);
    fill(255, lifespan);
    ellipse(location.x, location.y, mass*10, mass*10);
  }

  boolean dead() {
    if (lifespan<0) {
      return true;
    } else {
      return false;
    }
  }

}

class Repel{

    float mass;
    PVector location;
    Repel(){
        location = new PVector(width/2,height/2);
        mass = 100;
    }
    

    PVector repel(Particle p, PVector mousepos_){
        location = mousepos_;
        PVector force = PVector.sub(location, p.location);
        float distance = force.mag();
        distance = constrain(distance,5,25);
        force.normalize();

        float strength = (mass * p.mass)/ (distance * distance);
        force.mult(-strength);
        return force;
    }
    void display(){
        stroke(0);
        fill(133,50);
        // ellipse(location.x,location.y, mass*2,mass*2);
    }

    

}