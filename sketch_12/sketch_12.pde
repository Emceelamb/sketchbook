float space = 10;
int it;
float rot;
void setup(){
    size(600,600);
    background(33);
    frameRate(8);
}

void draw(){
    stroke(233);
    int c = int(random(255));
    pushMatrix();
    translate(0,it*20);
    noStroke();
    fill(33);
    rect(0,0,width,20);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int j = 0; j < 40; j++){
        pushMatrix();
        translate(j*20, 20*it);
        if(random(1)<0.5){
            line(0,0,20,20); 
        } else {   
            line(0,20,20,0);
        }
        popMatrix();
    }
    pushMatrix();
    translate(0,(height-it*20));
    noStroke();
    fill(33);
    rect(0,0,width,20);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int j = 0; j < 40; j++){
        pushMatrix();
        translate(j*20, (height-20*it));
        if(random(1)<0.5){
            line(0,0,20,0); 
        } else {   
            line(0,20,0,0);
        }
        popMatrix();
    }

    //  r to l

    pushMatrix();
    translate((width-it*20),0);
    noStroke();
    fill(33);
    rect(0,0,20,height);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int i = 0; i < 100; i++){
        pushMatrix();
        translate((width-20*it), 20*i);
        if(random(1)<0.5){
            line(0,0,20,20); 
        } else {   
            line(0,20,20,0);
        }
        popMatrix();
    }

    // l to r
    pushMatrix();
    translate(it*20,0);
    noStroke();
    fill(33);
    rect(0,0,20,height);
    popMatrix();
    stroke(255);
    strokeWeight(3);
    for(int i = 0; i < 100; i++){
        pushMatrix();
        translate(20*it, 20*i);
        if(random(1)<0.5){
            line(0,0,20,0); 
        } else {   
            line(0,20,0,0);
        }
        popMatrix();
    }


    //
    
    it++;
    if(it>30){
        it=0;
        // background(33);
    }
    rot+=0.001;

    // saveFrame("../images/goto10/goto_####.jpg");
}