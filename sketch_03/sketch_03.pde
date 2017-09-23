PGraphics pg;
color c;
float t;
float a = 0.0;
void setup(){
    size(600,600);
    pg = createGraphics(600,600);
    c = color(33,30);
    frameRate(120);
}

void draw(){
    // if(filled()){
    //     c = color(233,30);
    // } else {
    //     c = color(33,30);
    // }
    
    pg.beginDraw();
    pg.stroke(c);
    pg.strokeWeight(5);
    pg.noFill();
    pg.ellipse(x(t), y(t),60,60);
    pg.endDraw();
    
    translate(width/2,height/2);
    rotate(t);
    image(pg,0,0);
    t+=5;
    a+=1;
    println(a);
    if(a>400){
        a = 0;
        c = color(random(233),random(233),random(233),30);

    }

    // saveFrame("../images/spiral/spiral_#####.jpg");
}



boolean filled(){
    if(a>400){
        return true;
    } else {
        return false;
    }
}

float x(float t){
    return sin(t*10+t*5) * a;
 
}

float y(float t){
    return cos(t*10+t*5) * a;
}