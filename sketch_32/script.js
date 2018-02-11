var cols, rows;
var w = 40;
var grid = [];
var num = 1;
var current;

var stack = [];

function preload(){

}

function setup() {
    createCanvas(600,600);
    background(33);
    frameRate(5);


    cols = floor(width/w);
    rows = floor(height/w);

    for(var x = 0; x < rows; x++){
        for(var y = 0; y < cols; y++){
            var cell = new Cell(x,y);
            grid.push(cell);
        }
    }

current = grid[0];

}


function draw(){
    for(var i = 0; i<grid.length;i++){
        grid[i].display();
    }
    console.log(current.visited);
    current.visited = true;

    
    var next = current.checkNeighbors();

    stack.push(current);

    removeWalls(current, next);

    if(next){
        next.visited = true;
        current = next;
    } else if(stack.length > 0) {
        current =  stack.pop();

    }
}


function Cell(i,j){
    this.i = i;
    this.j = j;
    
    this.walls = [true, true, true, true];
    
    this.visited = false;
    
        this.checkNeighbors = function(){
            
            var neighbors = [];
    
            var top = grid[index(i,j-1)];
            var right = grid[index(i+1, j)];
            var bottom = grid[index(i, j+1)];
            var left = grid[index(i-1,j)];
    
            if(top && !top.visited){
                neighbors.push(top);
            }
            if(right && !right.visited){
                neighbors.push(right);
            }
            if(bottom && !bottom.visited){
                neighbors.push(bottom);
            }
            if(left && !left.visited){
                neighbors.push(left);
            }
    
            // console.log(neighbors.length);
            if(neighbors.length > 0){
                var ranNeigh = floor(random(0, neighbors.length));
                return neighbors[ranNeigh];
            } else {
                return undefined;
            }
    
        }

    this.display = function(){

        var x = this.i*w;
        var y = this.j*w;

        stroke(230,0,150,50);
        noFill();
        
        if(this.walls[0]){
            line(x, y + w, x, y);
        }
        
        if(this.walls[1]){
            line(x + w, y, x, y);
        }

        if(this.walls[2]){
            line(x, y, x, y + w);
        }

        if(this.walls[3]){
            line(x, y, x + w, y);
        }
        
        if(this.visited){
            fill(233);
            noStroke();
            rect(x,y, w, w);
        }
    }

}

function index(i, j){

    if(i < 0 || j < 0 || i > cols-1 || j > rows-1){
        return -1;
    }

    return i + j * cols;
}

function removeWalls(a,b){
    var x = a.i - b.i;
    if(x == 1){
        a.walls[3] = false;
        b.walls[1] = false;
    } else if( x == -1){
        a.walls[1] = false;
        b.walls[3] = false;
    }

    var y = a.j-b.j;
    if(y == 1){
        a.walls[0] = false;
        b.walls[2] = false;
    } else {
        a.walls[2] = false;
        b.walls[0] = false; 
    }
}
