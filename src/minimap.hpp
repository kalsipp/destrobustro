#pragma once
#include <map>
#include <string>
#include "map.hpp"
#include "ui.hpp"

class Minimap{
public:
  Minimap(Ui * ui, Map * map, int, int, int, int);
  void paint(int cx, int cy); //Paints minimap around centerpoint
private:
  Map * m_map = nullptr;
  Ui * m_ui = nullptr;
  int m_px = 0;
  int m_py = 0;
  int m_sizex = 0;
  int m_sizey = 0;
  std::string m_id = "minimap";
};

