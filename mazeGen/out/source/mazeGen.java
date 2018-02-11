import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class mazeGen extends PApplet {

// Init cols and rows
int cols, rows;
// size of Cell
int w = 40;



// grid
Cell[][] grid;
// ArrayList<Cell> neighbors = new ArrayList<Cell>();
Cell[] neighbors = new Cell [4];

// Active Cell
Cell currentCell;

public void setup(){
  
  background(33);

  // Number of cols and rows are width/ cell width
  cols = width/w;
  rows = height/w;

  // Declares grid
  grid = new Cell[cols][rows];
  for(int i= 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      // Cell cell = new Cell(i,j);
      grid[i][j] = new Cell(i,j);
    }
  }

  // Declare initial current cell
  currentCell = grid[0][0];
  // currentCell.visited = true;
}

public void draw(){
  for(int i = 0; i<grid.length; i++){
    for(int j = 0; j<grid.length;j++){
      grid[i][j].display();
    }
  }
      

  // if cell has been visited turn it true

  currentCell.visited = true;
  currentCell.checkNeighbors();
}

class Cell{
  int x,y;
  int i;
  int j;

  // Boolean check if there is a wall

  boolean walls[]= {true,true,true,true};

  boolean visited = false;
  

  // Init cells

  Cell(int i_,int j_){
    i = i_;
    j = j_; 
    x = i*w;
    y = j*w;
  }

  public void display(){
    // rect(x,y, x+w, y+w);
    stroke(255);
    if(walls[0]){
      line(x,     y,     x + w, y);
    }
    if(walls[1]){
      line(x + w, y,     x + w, y + w);
    }
    if(walls[2]){
      line(x + w, y + w, x    , y + w);
    }
    if(walls[3]){
      line(x,     y + w, x    , y + w);
    }

    // fill visited cells
    if (visited){
      fill(255);
      rect(x,y,w,w);
    }
  }

  public void checkNeighbors(){
    Cell top = grid[this.i][this.j-1];
    Cell right = grid[this.i+1][this.j];
    Cell bottom = grid[this.i][this.j+1];
    Cell left = grid[this.i-1][this.j];
    
    println(top);
    // if(!top.visited){

    }  

}

 
  public void settings() {  size(600,600); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "mazeGen" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
