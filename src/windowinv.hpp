#pragma once
#include <string>

#include "ui.hpp"


class Windowinv{
public:
  Windowinv(Ui * ui, int px, int py, int sizex, int sizey);
  ~Windowinv();
  Ui * m_ui = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  std::string m_wina = "windowinva";
  std::string m_winb = "windowinvb";
  //std::string m_winc = "windowinvc";
};
