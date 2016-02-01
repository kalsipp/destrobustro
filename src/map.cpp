#include "map.hpp"
#include <cassert> //debug

Map::Map(){
  
}

void Map::generate_map_from_file(std::string filename){
  Mapgenerator g;
  g.generate_map(1000, filename);
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
void Map::discover(int px, int py){

  for(int y = -1; y != 2; ++y){
    for(int x = -1; x != 2; ++x){
      std::pair<int, int> k(px+x, py+y);
      if(m_discovered.count(k) != 0){
        if(!m_discovered[k]){
          ++m_spaces_discovered;
        }
      }
      m_discovered[k] = true;
    }
  }
  
}
bool Map::is_discovered(int px, int py){
  std::pair<int, int> k(px, py);
  if(m_discovered.count(k) != 0){
    return m_discovered[k];
  }
  else{
    return false;
  }
}
void Map::make_wall(int px, int py){
  std::pair<int, int> k(px, py);
  m_discovered[k] = false;
  m_map[k] = '#';
}
void Map::make_floor(int px, int py){
  std::pair<int, int> k(px, py);
  m_discovered[k] = false;
  m_map[k] = '.';
}

