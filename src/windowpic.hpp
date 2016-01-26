#pragma once
#include <string>
#include "ui.hpp"
#include "imgcontainer.hpp"
#include "pixel.hpp"
class Windowpic{
public:
  Windowpic(Ui * ui, int px, int py, int sizex, int sizey);
  ~Windowpic();
  void print();
  void cursorpos(int, int);
  Ui* m_ui = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  Img_container * m_img = nullptr;
};
