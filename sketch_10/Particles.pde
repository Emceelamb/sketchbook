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
    bd.linearDamping = 0.8;
    bd.angularDamping = 0.9;
    body = box2d.createBody(bd);

    PolygonShape ps = new PolygonShape();
    float box2dW = box2d.scalarPixelsToWorld(w/2);
    float box2dH = box2d.scalarPixelsToWorld(h/2);

    ps.setAsBox(box2dW, box2dH);

    FixtureDef fd = new FixtureDef();
    fd.shape = ps;
    fd.density = random(2,4);
    fd.friction = 0.3;
    fd.restitution =0.5;
    body.createFixture(fd);
  }
  
  
  void update() {
    // body.setLinearVelocity(new Vec2(0,3));
    // body.setAngularVelocity(1,2);
  }

  void checkEdges() {
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
  
  void display() {
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