#include "windowinfo.hpp"

Windowinfo::Windowinfo(Ui * ui, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowinfoborder");
  m_ui->create_window_scroll(m_px+1, m_py+1, m_sizex-2, m_sizey-2, m_id);
  m_ui->print_line("This is infowindow", m_id);
  m_ui->print_line("News appear here", m_id);
}

Windowinfo::~Windowinfo(){
  
}
