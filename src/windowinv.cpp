#include "windowinv.hpp"

Windowinv::Windowinv(Ui * ui, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  int partsize = sizex/3;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowinvborder");
  //m_ui->create_window_scroll(m_px+1, 
}

Windowinv::~Windowinv(){

}
