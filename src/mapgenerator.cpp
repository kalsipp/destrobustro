
#include "mapgenerator.hpp"
Mapgenerator::Mapgenerator(){
}

void Mapgenerator::generate_map(int size, std::string filename){
  m_width = size;
  m_height = m_width;
  std::vector<Room> k;
  Room r;
  k.resize(m_width, r);
  m_grid.resize(m_height, k);
  carve(0,0);
  std::ofstream file;
  file.open(filename.c_str());
  std::string row;
  row.resize(m_width, '#');
  row += '\n';
  file << row;
  for(int y = 0; y < m_height; ++y){
    row = "#";
    for(int x  = 0; x < m_width; ++x){
    
      if(m_grid[y][x].carved || m_grid[y][x].open){
        row += ' ';
      }else{
        row += '#';
      }
    }
    row += '\n';
    file << row;
  }
  file.close();
}

void Mapgenerator::carve(int cx, int cy){
  //Recursive backpropagation algorithm
  std::vector<int> dir = m_directions;
  std::random_shuffle(dir.begin(), dir.end());
  for(int i = 0; i < 4; ++i){
    int d = dir[i];
    int nx = cx + 2*m_dx[d];
    int ny = cy + 2*m_dy[d];
    if(nx < m_width && nx >= 0 && ny < m_height && ny >= 0){
      if(!m_grid[ny][nx].carved){
        m_grid[ny][nx].carved = true;
        m_grid[cy][cx].walls[d] = true;
        m_grid[cy+m_dy[d]][cx+m_dx[d]].open = true;
        carve(nx, ny);
      }
    }
  }
}

