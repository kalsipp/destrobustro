#pragma once

#include <sys/ioctl.h>
#include <string>
#include <vector>
#include "ui.hpp"
//class Ui;
class Windowinfo{
public:
  Windowinfo(Ui * ui, int px, int py, int sizex, int sizey);
  ~Windowinfo();
  void print(std::string text);
  Ui * m_ui = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  int m_cols = 0;
  int m_rows = 0;
  std::string m_id = "windowinfo";
  std::vector<std::string> m_history;
};
