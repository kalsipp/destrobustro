#include "windowinv.hpp"

Windowinv::Windowinv(Ui * ui, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  if(sizex%2 != 0) sizex -=1;
  int partsize = sizex/2;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowinvborder");
  m_ui->create_window_scroll(m_px+1, m_py+1, partsize-1, m_sizey-2, m_wina);
  m_ui->create_window_scroll(m_px+partsize, m_py+1,partsize-1, m_sizey-2, m_winb);
  /*
  for(int i = 0; i < 100; ++i){
    for(int j = 0; j < 100; ++j){
      m_ui->print_line_at(i, j, "x:" + std::to_string(i) + " y:" + std::to_string(j), m_wina);
    }
  }
  */
  //
  //m_ui->print_line("Hello", m_wina);
  m_ui->print_line_at(0,0,"This is inventory",m_wina);
  m_ui->print_line_at(0,0, "This is also inventory", m_winb);
  m_ui->print_line_at(0,4, "I can print wherever I want", m_wina); 
  //m_ui->create_window_scroll(m_px+1, 
}

Windowinv::~Windowinv(){

}
