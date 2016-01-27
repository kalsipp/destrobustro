#pragma once

#include <vector>
#include <fstream>
#include <iostream>
class Map{
public:
  Map();
  void generate_map_from_file(std::string filename);
  void make_wall(int x, int y);
  void make_floor(int x, int y);
};
