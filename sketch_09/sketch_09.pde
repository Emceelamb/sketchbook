float t;
PImage img;
void setup(){
    size(1383,2048);
    img = loadImage("/data/heads.jpg");
    img.loadPixels();
}

void draw(){
    background(233);
    
    for(int i = 1; i < 130; i++){
        for(int j = 1; j < 200; j++){
            float x_ = x(t)+10*i;
            float y_ = y(t)+10*j;
            color c = img.get(int(x_),int(y_));
            strokeWeight(map(brightness(c),0,255,8,4));
            stroke(c);
            pushMatrix();
            // translate(10*i,10*j);
            point(x_,y_);
            popMatrix();
        }
    }   

    t++;
}

float x(float t){
    return sin(t/10)*10;
}


float y(float t){
    return cos(t/10)*10;
}