#include "map.hpp"
#include <cassert> //debug

Map::Map(){
  
}

void Map::generate_map_from_file(std::string filename){
  std::ifstream file(filename.c_str());
  std::string line;
  int x = 0;
  int y = 0;
  while(std::getline(file, line)){
    x = 0;
    while(line.length() > 0){
      char c = line[0];
      line.erase(line.begin());
      if(c == '#'){
        make_wall(x, y);
      }else if(' '){
        make_floor(x, y);
      }

      ++x;
    }
    ++y;
  }
  file.close();
}

const std::map<std::pair<int, int>, char>& Map::get_map(){
  /*
  for(auto i = m_map.begin(); i != m_map.end(); ++i){
    std::cout << (*i).second << std::endl;
  }
  assert(false);
  */
  return m_map;
} 

bool Map::space_free(int px, int py){
  std::pair<int, int> k (px, py);
  if(m_map.count(k) != 0){
    if(m_map[k] == '#'){
      return false;
    }
  }
  return true;
}

void Map::make_wall(int px, int py){
  std::pair<int, int> k(px, py);
  m_map[k] = '#';
}
void Map::make_floor(int px, int py){
  std::pair<int, int> k(px, py);
  m_map[k] = '.';
}
