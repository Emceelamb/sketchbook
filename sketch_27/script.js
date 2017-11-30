function preload(){
    sound = loadSound('november.mp3');
}

function setup() {
    var cnv = createCanvas(1280,720);
    background(33);
    cnv.mouseClicked(togglePlay);
    fft = new p5.FFT(0.8);
}


function draw(){

    background(33);
    var spectrum = fft.analyze();
    var bass = fft.getEnergy("bass");
    var mid = fft.getEnergy("mid");
    var hi = fft.getEnergy("treble");
    
    noStroke();
    noFill();
    // fill(0,255,0); // spectrum is green
    
    // var waveform = fft.waveform();
    // noFill();
    // beginShape();
    // stroke(255,0,0); // waveform is red
    // strokeWeight(1);
    // for (var i = 0; i< waveform.length; i++){
    //   var x = map(i, 0, waveform.length, 0, width);
    //   var y = map( waveform[i], -1, 1, 0, 66*i
    //   vertex(x,y);
    // }
    // endShape();

    
    // var basewave = bass.waveform();
    // noFill();
    // beginShape();
    // stroke(0,255,0); // waveform is red
    // strokeWeight(1);
    // for (var i = 0; i< waveform.length; i++){
    //   var x = map(i, 0, waveform.length, 0, width);
    //   var y = map( waveform[i], -1, 1, 0, 66*i
    //   vertex(x,y);
    // }
    // endShape();
    // translate(200,0);
    for(var i =0; i<9;i++){
        for(var j=0; j<9;j++){

            var bSize= map(bass,0,255,0,33);
            rectMode(CENTER);
            stroke(0,255,0);
            rect(66*i,66*j, bSize, bSize);
        
            var midSize= map(mid,0,255,0,66);
            ellipseMode(CENTER);
            stroke(0,0,255);
            ellipse(66*i,66*j, midSize, midSize);
        
            var hiSize= map(hi,0,255,0,66);
        stroke(255,0,255);
        triangle(66*i-1*hiSize,j*66+1*hiSize, 66*i,j* 66-1*hiSize, 66*i+1*hiSize,j*66+1*hiSize);
    }
}
  
}

function togglePlay(){
    if(sound.isPlaying()){
        sound.pause();
    } else {
        sound.loop();
    }
}