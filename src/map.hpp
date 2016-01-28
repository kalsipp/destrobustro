#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <map>
//#include <pair>
class Map{
public:
  Map();
  void generate_map_from_file(std::string filename);
  void make_wall(int x, int y);
  void make_floor(int x, int y);
  bool space_free(int x, int y);
  const std::map<std::pair<int, int>, char> & get_map();
private:
  std::map<std::pair<int, int>, char> m_map;

};
