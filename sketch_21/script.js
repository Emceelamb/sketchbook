var ps =[];

function preload(){

}

function setup() {
    createCanvas(1280,720);
    background(33);
    for(var i = 0; i<20; i++){
        ps[i] = new Particle(createVector(random(width),random(height)));
    }
    // p1  = new Particle(createVector(100,100));
    // p2  = new Particle(createVector(200,100));
}


function draw(){
    var f = createVector(0,0.01);
    // p1.aforce(f);
    // p1.update();
    // p1.draw();
    // p2.draw();
    // ps.push(new Particle(createVector(width/2,height/2)));
    for (var i = ps.length; i < 10; i++) {
        var p = new Particle(createVector(random(width),random(height)));
        ps.push(p);
    }
    for(var i = 0; i< ps.length; i++){
        ps[i].aforce(f);
        ps[i].update();
        ps[i].dead();
        ps[i].display();
        if(ps[i].dead()){
            ps.splice(i,1);
        }
        console.log(ps[i].lifespan);
    }
    // if(ps.length<20){
    //     ps.push(new Particle(width/2,height/2));
    // }
    console.log(ps.length+"!"   );
}

var Particle = function(position){
    this.position = position;
    this.acc = createVector(0,0);
    this.vel = createVector(random(-1,1,random(-1,1)));
    this.grav = createVector(0,0);
    this.mass = random(10.0);
    this.lifespan = 255;
    this.dead = false;

    this.aforce = function(force){
        this.force = force;
        this.f = p5.Vector.div(this.force,this.mass);
        this.acc.add(this.f);
    }

    this.update = function(){
        this.vel.add(this.acc);
        this.position.add(this.vel);
        this.lifespan-=5;
    }
    
    this.display = function(){
        fill(233,this.lifespan);
        ellipse(this.position.x,this.position.y, 40,40);
    }

    // this.addPs = function(){
    //     this.
    // }

    this.dead = function(){
        if(this.lifespan<0){
            console.log("Death!");
            // ps.splice(1);
            // ps.push(new Particle(createVector(width/2,height/2)));
            return true;
        }


    }
}

// class Particle {
//     constructor(position){
//         this.position = position;
//     }   
//     this.prototype.draw = function(){
//         ellipse(this.position.x,this.position.y);
//     }
// }

// Particle.prototype.draw = function (){
//     console.log("hello");
//     fill(233);
//     ellipse(this.position.x,this.position.y, 40,40);
// }