#pragma once
#include <string>
#include <fstream>
#include "ui.hpp"
#include "imgcontainer.hpp"
#include "pixel.hpp"
#include "map.hpp"
#include "windowinfo.hpp"
class Windowpic{
public:
  Windowpic(Ui * ui, Map * map, int px, int py, int sizex, int sizey);
  ~Windowpic();
  void print(int px, int py, int direction, Windowinfo * wininfo );
private:
  void cursorpos(int, int);
  void hide_cursor();
  void load_image(int, int, std::string filename);
  void clear_image();
  void choose_image(int, int, int, Windowinfo * wininfo);
  Ui* m_ui = nullptr;
  Map* m_map = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  Img_container * m_img = nullptr;
  std::string m_last_picture = "-1";
  std::vector<std::vector<Pixel>> m_grid;
};
