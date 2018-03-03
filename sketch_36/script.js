var capture;

function preload(){

}

function setup() {
    var canvas = createCanvas(windowWidth,windowHeight);
    background(33);
    capture = createCapture(VIDEO);
    capture.size(320,480);
    canvas.parent('webcam-bg');
}


function draw(){
    image(capture,0,0,windowWidth,windowHeight);
}

function windowResized() {
    resizeCanvas(windowWidth, windowHeight);
  }