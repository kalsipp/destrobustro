#pragma once

#include <sys/ioctl.h>

#include "ui.hpp"
//class Ui;
class Windowinfo{
public:
  Windowinfo(Ui * ui, int px, int py, int sizex, int sizey);
  ~Windowinfo();
  Ui * m_ui = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  int m_cols = 0;
  int m_rows = 0;
  std::string m_id = "windowinfo";
};
