float t;

void setup(){
    size(640,640);
    background(33);
    t =0.0;
}

void draw(){

    
    
    noStroke();
    translate(50,50);
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10;j++){

            float c = map(noise(t)*j*i,0,10,0,233);
            fill(c);
            ellipseMode(CENTER);
            ellipse(60*i,60*j,40,40);
        }
    }
    
    t+=0.01;
}

