int value = 0;

void setup() {
  size(640, 640);
}

void draw() {
  //textMode(CENTER);
  background(200);
  fill(value);
  rect(200,200,200,200);

  String a = "hello";
  String b = "O";
  textSize(48);
  textAlign(CENTER);
  fill(33);
  if (mousePressed) {
    text(b, width/2, height/2);
  } else {
    text(a, width/2, height/2);
  }
  
  
}


void keyPressed() {
  if (value == 0) {
    value = 255;
  } else {
    value = 0;
  }
  println("pressed" + int(key));
}


void keyTyped() {
  println("typed " + int(key) + " " + keyCode);
}

void keyReleased() {
  println("released " + int(key) + " " + keyCode);
}