#include "map.hpp"


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


void Map::make_wall(int px, int py){
}
void Map::make_floor(int px, int py){
}
