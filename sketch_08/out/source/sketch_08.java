import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import gab.opencv.*; 
import java.awt.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_08 extends PApplet {




PImage im;
PGraphics of;
PGraphics[] flist;
OpenCV opencv;

int sw = 1383;
int sh = 2048;

public void setup(){
    
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
public void draw(){
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
               int c = color(r,g,b);
               if(c!=0){
                // pixels[loc+my]=color(r,g,random(255));
                int z = PApplet.parseInt(random(width));
                int l = PApplet.parseInt(random(height));
                fill(c);
                noStroke();
                rect(z,l,30,30);                
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
    // saveFrame("../images/color/heads_#####.jpg");   
}

  public void settings() {  size(1383,2048); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_08" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
