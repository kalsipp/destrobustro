#include <iostream>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <chrono>
#include <ios>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "textgraphics.hpp"
#include "pixel.hpp"
#include "imgcontainer.hpp"
//#### Special member functions ####
//#### Constructor
Textgrafs::Textgrafs(){ 
  std::cout << std::unitbuf; //Turns off the buffer
  std::ios_base::sync_with_stdio(false); //Turn off sync with in stream

  struct winsize w; //Get size of window
  ioctl(0, TIOCGWINSZ, &w);
  rows_ = w.ws_row;
  cols_ = w.ws_col*0.5;
  std::vector<std::string> p;
  std::string k = "  ";
  p.resize(cols_,k);
  grid.resize(rows_,p);  
}

//#### Member functions

void Textgrafs::cursorpos(int px, int py){
  ++px; //escape is 1 base
  ++py;
  std::cout << "\033[" << py << ";" << px << "H";
} 
std::string Textgrafs::cursorpos_str(int px, int py){
  ++px;
  ++py;
  std::string s = "\033[" + std::to_string(px) + ";" + std::to_string(py) + "H";
  return s;
}
void Textgrafs::hide_cursor(){
  std::cout << "\033[?25l";//TODO look up this code
}
void Textgrafs::show_cursor(){
  std::cout << "\033[?25h";
}
void Textgrafs::clear_screen(){
  std::cout << "\033[2J";
}

void Textgrafs::save_old_grid(){
  old_grid = grid;
}

void Textgrafs::add_image(const std::vector<std::vector<Pixel>> & imgref, int px, int py){
  for(int y = 0; y <  imgref.size(); ++y){
    for(int x = 0; x < imgref[y].size(); ++x){
      add_pixel(imgref[y][x], px+x, py+y);
    }
  }
}

void Textgrafs::add_image(const Img_container & img, int px, int py){
  add_image(img.get_img(), px, py);
}

void Textgrafs::print(){
  cursorpos(0,0);
  hide_cursor();
  std::string s;
  for(int y = 0; y < grid.size(); ++y){
    for(int x = 0; x < grid[y].size();++x){
      s+= grid[y][x];
    }
    s+= "\033[0m\n";
  }
  s.pop_back();
  std::cout << s;
  show_cursor();
}
void Textgrafs::fill_grid(const Pixel & p){
  for(int y = 0; y < rows_; ++y){
    for(int x = 0; x < cols_; ++x){
      add_pixel(p, x, y);
    }
  }
}
void Textgrafs::clear_grid(){
  //Fills the grid with space
  for(int y = 0; y < grid.size(); ++y){
    for(int x = 0; y < grid[y].size();++x){
      Pixel p;
      add_pixel(p, x, y);
    }
  }
}
void Textgrafs::clear_grid_specific(int px, int py, int sizex, int sizey){
  for(int y = py; y < py+sizey; ++y){
    for(int x = px; x < px+sizex; ++x){
      Pixel p;
      add_pixel(p,x,y);
    }
  } 
}

void Textgrafs::add_pixel(const Pixel & p, int px, int py){
  if(px < 0 || px >= cols_) return;
  if(py < 0 || py >= rows_) return;
  //std::cout << "py " << py << std::endl;
  //std::cout << "px " << px << std::endl;
  //std::cout << "y size " << grid.size()<<std::endl;
  //std::cout << "x size " << grid[py].size() <<std::endl;
  grid[py][px] = p.get_str();
}
