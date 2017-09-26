PImage img; 
PImage sorted;
int sw = 1383;
int sh = 2048;

void setup(){
    size (1383, 2048);
    img = loadImage("/data/heads.jpg");
    sorted = createImage(img.width, img.height, RGB);
    img.loadPixels();
    // for(int i = 0; i<img.pixels.length; i++){
    //     sorted.pixels[i] = img.pixels[i];
    // }
    sorted = img.get();
    sorted.loadPixels();
}
int sample_size = int(random(20,80));
void draw(){
    
    // image(img,0,0);

    float x = random(width);
    float y = random(height);
    color c = img.get(int(x), int(y));
    fill(c);
    noStroke();
    rect(x,y,60,60);

}