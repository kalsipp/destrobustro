#include "windowpic.hpp"
#include <cassert>
Windowpic::Windowpic(Ui * ui, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowpic");
  m_img = new Img_container("img_output");
}

Windowpic::~Windowpic(){
  delete m_img;
}
void Windowpic::cursorpos(int px, int py){
  ++px;
  ++py;
  std::cout << "\033["<<py<<";"<<px<<"H";
}
void Windowpic::print(){
  std::vector<std::vector<Pixel>> grid = m_img->get_img();
  int sx = m_px+1;
  int sy = m_py+1;
  int mx = m_sizex/2 -2;
  int my = m_sizey-3;
  std::cout << m_sizex << std::endl;
  //assert(false);
  //std::cout << grid.size() << std::endl;
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
  //s.pop_back();
  //std::cout << s;
}
