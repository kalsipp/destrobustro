#include "minimap.hpp"
#include <cassert> //debug
Minimap::Minimap(Ui * ui, Map * map, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_map = map;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, m_id);
}

void Minimap::paint(int cx, int cy){
  /*
    cx, cy is player position
    prints around the player
    screen 0,0 = cx-sizex/2, cy-sizey/2
    screen size, size = cx+sizex/2, cy+sizey/2
    so go from x=-size/2 to size/2
    get cx + x;
  */
  
  std::map<std::pair<int, int>, char> map (m_map->get_map());
  std::string row;
  for(int y = -m_sizey/2; y < m_sizey/2; ++y){
    row = "";
    for(int x = -m_sizex/2; x < m_sizex/2; ++x){
      
      //std::cout << x << " " << y << std::endl;
      std::pair<int, int> k(cx+x,cy+y);
      if(x == 0 && y == 0){
        row += '@';
      }
      else if(map.count(k) != 0){
        row += map[k];
      }else{
        row += '-';
      }
    }
    m_ui->print_line_at(1, y+m_sizey/2, row, m_id);
  }
}
