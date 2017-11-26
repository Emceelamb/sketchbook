float t = 0.0;
float[] seed = new float[16];
float[] speed = new float[16];

void setup(){
    size(640,640);
    background(33);
    for(int i = 0; i<seed.length; i++){
        seed[i]=random(-width/2,width/2);
        print(seed[i]);
    }
    for(int i = 0; i<speed.length; i++){
        speed[i]=random(0,1);
    }
}

void draw(){
    background(255);
    // map(value, low1, high1, low2, high2);
    t+=0.01;
    translate(0,height/2);
    for(int i =0; i<16;i++){
        float x = map(noise(t+speed[i]),0,1,-width/2,width/2)+seed[i];
        float col = map(abs(x),0,width/2,255,0);
        // float col = map(abs(x),0,width/2,0,255);
        noStroke();
        fill(0,col);
        println(x);
        rect(i*40,0,40,x);
    }
    saveFrame("/out/#####.jpg");
}