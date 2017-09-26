import gab.opencv.*;
import java.awt.*;

PImage im;
PGraphics of;
PGraphics[] flist;
OpenCV opencv;

int sw = 1383;
int sh = 2048;

void setup(){
    size(1383,2048);
    im = loadImage("/data/heads.jpg");
    of = createGraphics(sw,sh);
    // of.beginDraw();
    // of.image(im,0,0);
    // of.endDraw();
    opencv = new OpenCV(this,sw,sh);
    opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);  

    image(im,0,0);
}
int x = 0;
int y = 0;
int mx = 0;
int my = 0;
void draw(){
    opencv.loadImage(im);
    // background(255);
    Rectangle[] faces = opencv.detect();
    
    for(int i = 0; i<faces.length; i++){
        of.beginDraw();
        of.copy(im,faces[i].x,faces[i].y, faces[i].width, faces[i].height, faces[i].x,faces[i].y,faces[i].width,faces[i].height);
        of.endDraw();
        loadPixels();
        of.loadPixels();
                   

        for(int y = 0; y < of.height; y++){
            for(int x = 0; x < of.width; x++){
                
        // if(y < of.height){
        //     if(x < of.width){
                
               int loc = x + y * width;
               
               float r = red(of.pixels[loc]);
               float g = green(of.pixels[loc]);
               float b = blue(of.pixels[loc]);
               if(of.get(x,y)!=0){
                    println(i);
                    pixels[loc+my]=color(r,g,random(255));
                    }
                    //  else {

                    // pixels[loc+my]=color(r,g,random(255));
                    // }
               
               
            }
        }
        updatePixels();
        my++;
        mx-=2;
        y++;
        
        // image(im,0,0);


        // strokeWeight(4);        
        // rect(faces[i].x,faces[i].y,faces[i].width,faces[i].height);
        // flist[i] = copy(im,faces[i].x,faces[i].y,faces[i].width, faces[i].height,faces[i].x,faces[i].y,faces[i].width, faces[i].height);
    }
    // println(flist.length);    
    
}

