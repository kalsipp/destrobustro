#include "windowinfo.hpp"
#include <cassert>
Windowinfo::Windowinfo(Ui * ui, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowinfoborder");
  m_ui->create_window_scroll(m_px+1, m_py+1, m_sizex-2, m_sizey-2, m_id);
  m_ui->print_line("This isinfowindow", m_id);
  m_ui->print_line("News appear here", m_id);
  m_ui->print_line("Scrollingly.", m_id);
}

Windowinfo::~Windowinfo(){
  
}


void Windowinfo::print(std::string text){
  m_history.push_back(text);
  if((int)m_history.size() > m_sizey-2){
    m_history.erase(m_history.begin());
  }
  int x = 0;
  int y = 0;
  std::string clearer = "                              ";//Todo Make this nicer
  for(auto i = m_history.begin(); i != m_history.end(); ++i){
    m_ui->print_line_at(x,y, clearer, m_id);
    m_ui->print_line_at(x,y,*i, m_id);
    ++y;
  }

}
