Planet sun;

void setup(){
  size(600,600);
  background(0);
  sun = new Planet(100,100);
  sun.makeMoons(3);

}

void draw(){
  translate(width/2,height/2);
  sun.display();
}

class Planet {
  float dist;
  float rad;
  float angle;
  Planet[] planets;
  
  Planet(float d, float r){
    dist = d;
    rad = r;
    angle = 0;
  }
  
  void makeMoons(int total){
    planets = new Planet[total];
    float r = rad * 0.5;
    float d = random(50,100);
     for(int i =0; i<planets.length; i++){
       planets[i]= new Planet(r,d);
     }
  }
  
  void display(){
     ellipse(0,0, rad,rad); 
     pushMatrix();
     translate(dist,0);
     popMatrix();
     if(planets!=null){
       
       for(int i = 0; i<planets.length; i++){
         planets[i].display();
       }
     }
  }
}