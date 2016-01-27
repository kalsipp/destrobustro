#include "windowpic.hpp"
#include <cassert> //debugging
Windowpic::Windowpic(Ui * ui, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowpic");
  m_img = new Img_container("img_output.img");
  std::vector<Pixel> p;
  Pixel pix;
  p.resize(m_sizex/2, pix);
  m_grid.resize(m_sizey, p);
  
}

Windowpic::~Windowpic(){
  delete m_img;
}
void Windowpic::cursorpos(int px, int py){
  ++px;
  ++py;
  std::cout << "\033["<<py<<";"<<px<<"H";
}

void Windowpic::hide_cursor(){
  std::cout << "\033[?25h";
}

void Windowpic::load_image(int px, int py, std::string filename){
  //m_img->init_img(filename);
  //std::vector<std::vector<Pixel>> grid = init_img.get_img();
  //for(int y = 0; y < 
  //for(
}

void Windowpic::print(){
  std::vector<std::vector<Pixel>> grid = m_img->get_img();
  int sx = m_px+1;
  int sy = m_py+1;
  int mx = m_sizex/2 -2;
  int my = m_sizey-3;
  cursorpos(sx, sy);
  std::string s;
  for(int y = 0; y < grid.size(); ++y){
    std::string s;
    for(int x = 0; x < grid[y].size(); ++x){
      if(y <= my && x <= mx){
	s+= grid[y][x].get_str();
      }
    }
    s+="\033[0m";
    cursorpos(sx, sy);
    sy++;
    std::cout << s;
  }
  hide_cursor();
  //s.pop_back();
  //std::cout << s;
}
