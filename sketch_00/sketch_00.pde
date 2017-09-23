Spinner[][] spinners  = new Spinner[120][120];

void setup(){
    size(600,600, OPENGL);
    ortho();
    for(int i = 0; i<spinners.length; i++){
        for(int j = 0; j <spinners[1].length; j++){
            spinners[i][j] = new Spinner(36.0);
        }
    }
}
float rot = 0.;
void draw(){
    background(#476a6f);
    // pushMatrix();
    // translate(width/2,height/2,-500);
    // rectMode(CENTER);
    // rotateZ(rot);
    // rotateY(rot);
    // rect(0,0,400,400);
    // popMatrix();
    rot-=0.1;
    for(int i = 0; i < spinners.length; i++){
        for(int j = 0; j <spinners[1].length; j++){
            pushMatrix();
            translate(i*spinners[0][0].rad,j*spinners[0][0].rad);
            spinners[i][j].update();
            spinners[i][j].display();
            popMatrix();
        }
    }

    
}

class Spinner{
    float x,y,z;
    float rad;
    Spinner(float rad_){
        x = 0;
        y = 0;
        z = 0;
        rad = rad_;

    }
    void update(){
        y += 0.05;
        z += 0.05;
    }

    void display(){
        pushMatrix();
        rotateY(y);
        rotateZ(z);
        // noFill();
        // strokeWeight(5);
        stroke(#476a6f);
        fill(#7eb09b);
        rectMode(CENTER);
        rect(0, 0, rad, rad);
        popMatrix();
    }
}
