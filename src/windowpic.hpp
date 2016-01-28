#pragma once
#include <string>
#include "ui.hpp"
#include "imgcontainer.hpp"
#include "pixel.hpp"
#include "map.hpp"
class Windowpic{
public:
  Windowpic(Ui * ui, Map * map, int px, int py, int sizex, int sizey);
  ~Windowpic();
  void print(int px, int py, int direction);
  void cursorpos(int, int);
  void hide_cursor();
  void load_image(int, int, std::string filename);
  void clear_image();
  void choose_image(int, int, int);
  Ui* m_ui = nullptr;
  Map* m_map = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  Img_container * m_img = nullptr;
  std::vector<std::vector<Pixel>> m_grid;
};
