import shiffman.box2d.*;
import org.jbox2d.collision.shapes.*;
import org.jbox2d.common.*;
import org.jbox2d.dynamics.*;

Box2DProcessing box2d;		

ArrayList<Heart> hearts;
ArrayList<Edge> edges;
PShape heart;

void setup() {
  size(640, 640);

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

void draw() {
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
    fd.friction = 0.3;
    fd.restitution = 0.5;
    body = box2d.createBody(bd);
    body.createFixture(fd);
  }

  void display(){
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