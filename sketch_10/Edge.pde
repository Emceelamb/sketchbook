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
    
  void display() {
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