#include "windowpic.hpp"
#include <cassert> //debugging
Windowpic::Windowpic(Ui * ui, Map * map, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_map = map;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowpic");
  m_img = new Img_container("media/tunnel.img");
  //m_img = new Img_container("img_output.img");
  std::vector<Pixel> p;
  Pixel pix;
  p.resize(m_sizex/2, pix);
  m_grid.resize(m_sizey, p);
//std::cout << "The size is:" << std::endl;
//std::cout << "X: " << m_grid[0].size() << std::endl;
//std::cout << "Y: " << m_grid.size() << std::endl;
//assert(false);
}

Windowpic::~Windowpic(){
  delete m_img;
  delete m_map;
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
  /*
    m_img->init_img(filename);
  //m_img->init_img(filename);
  std::vector<std::vector<Pixel>> grid = m_img->get_img();
  int tx = px + grid[0].size();
  int ty = py +grid.size();
  if(tx >= grid[0].size()) tx = grid[0].size()-1;
  if(ty >= grid.size()) ty = grid.size() -1;
 
  int gy = 0;
  for(int y = py; y != ty; ++y){
    int gx = 0; 
    for(int x = px; x != tx; ++x){
      if(y > 0 && x > 0 && gx < grid[0].size() && gy < grid.size()){
        m_grid[y][x] = grid[gy][gx];
      }
      ++gx;
    }
    ++gy;
  }
  */
  m_img->init_img(filename);
}

void Windowpic::print(int px, int py, int direction){
  choose_image(px, py, direction);
  
  std::vector<std::vector<Pixel>> grid = m_img->get_img();
  int sx = m_px+1;
  int sy = m_py+1;
  unsigned int mx = m_sizex/2 -2;
  unsigned int my = m_sizey-3;
  cursorpos(sx, sy);
  for(unsigned int y = 0; y < grid.size(); ++y){
    std::string s = "";
    for(unsigned int x = 0; x < grid[y].size(); ++x){
        s+= grid[y][x].get_str();
    }
    //s+="\033[0m";
    cursorpos(sx, sy);
    sy++;
    
    //m_ui->print_line_at(sx, sy, s, "windowpic");
    std::cout << s;//.length();
    std::cout.flush();
  }
}


void Windowpic::choose_image(int px, int py, int dir){
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int tmp = dir+2;
  if(tmp > 3) tmp -=4;
  //Is there a wall ahead
  if(!m_map->space_free(px+dx[tmp], py+dy[tmp])){
    m_img->init_img("media/wall.img");
    return;
  }
  //If the space ahead is clear, is there an opening to the right?
  px += dx[tmp];
  py += dy[tmp];
  tmp = dir +3;
  if(tmp > 3) tmp -=4;
  if(m_map->space_free(px + dx[tmp], py+dy[tmp])){
    m_img->init_img("media/right.img");
    return;
  }
  
  tmp = dir +1;
  if(tmp > 3) tmp -= 4;
  if(m_map->space_free(px+dx[tmp], py+dy[tmp])){
    m_img->init_img("media/left.img");
    return;
  }
  
  m_img->init_img("media/tunnel.img");
  

  
}
