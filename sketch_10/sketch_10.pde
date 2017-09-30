import shiffman.box2d.*;
import org.jbox2d.collision.shapes.*;
import org.jbox2d.common.*;
import org.jbox2d.dynamics.*;

Particle[] particles = new Particle[10];
Edge[] edges = new Edge[3];
Box2DProcessing box2d;		
void setup() {
  size(640, 640);

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

void draw() {
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