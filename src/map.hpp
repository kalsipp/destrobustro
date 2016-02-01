#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <map>
//#include <pair>
#include "mapgenerator.hpp"
struct Node{
  bool walls[4] = {false, false, false, false};
};

class Map{
public:
  Map();
  void generate_map_from_file(std::string filename);
  void make_wall(int x, int y);
  void make_floor(int x, int y);
  bool space_free(int x, int y);
  void discover(int x, int y);
  bool is_discovered(int x, int y);
  int m_spaces_discovered = 0;
  const std::map<std::pair<int, int>, char> & get_map();
private:
  std::map<std::pair<int, int>, char> m_map;
  std::map<std::pair<int, int>, bool> m_discovered;
};
