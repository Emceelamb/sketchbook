float t = 0.0;
float[] seed = new float[16];
float[] speed = new float[16];
float[] hght = new float[16];

void setup(){
    size(640,640);
    background(33);
    for(int i = 0; i<seed.length; i++){
        seed[i]=random(-width/2,width/2);
        print(seed[i]);
    }
    for(int i = 0; i<speed.length; i++){
        speed[i]=1;
    }
    for(int i = 0; i<hght.length; i++){
        hght[i]=1*seed[i];
    }

}

void draw(){
    background(186,225,255);
    // map(value, low1, high1, low2, high2);
    t+=0.01;
    translate(0,height);
    for(int i =0; i<16;i++){
        float x = map(noise(t+speed[i]),0,1,-width/2,width/2)+seed[i];
        float col = map(abs(x)*0.25,0,width/2,200,50);
        float h = noise(t+hght[i])*200;
        // float col = map(abs(x),0,width/2,0,255);
        noStroke();
        fill(30,30,80,col);
        println(x);
        // ellipse(i*40,h-40,40,40);
        for(int j = 0; j<30; j++){
            rect((i*40)+(20*i),h-(40*j)+(20*i),40,40);
        }
    }
    // saveFrame("/out1/#####.jpg");
}