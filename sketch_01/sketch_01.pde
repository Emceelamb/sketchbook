float inc = 0;

void setup(){
    size(600,600, OPENGL);

    ortho();
}
float rot = 0.;
void draw(){
    background(230);
    inc+=0.01;
    pushMatrix();
    translate(width/2,height/2);
    rotateY(map(mouseX,0,width,0,PI));
    rotateZ(map(mouseY,0,height,0,PI));
    noFill();
    box(150);
    popMatrix();
}
 