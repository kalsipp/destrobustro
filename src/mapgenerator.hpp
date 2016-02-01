#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>

struct Room{
  bool walls[4] = {false, false, false, false};
  bool carved = false;
  bool open = false;
};


class Mapgenerator{
public:
  Mapgenerator();
  void generate_map(int size, std::string filename);
private:
  void carve(int cx, int cy);
  std::vector<std::vector<Room>> m_grid;
  int m_width;
  int m_height;
  std::vector<int> m_directions = {0,1,2,3};
  int m_dx[4] = {0, 0, 1, -1};
  int m_dy[4] = {1, -1, 0, 0};
  int OPP[4] = {1, 0, 3, 2}; //?
  
};
