#include "windowpic.hpp"
#include <cassert> //debugging
Windowpic::Windowpic(Ui * ui, Map * map, int px, int py, int sizex, int sizey){
  m_ui = ui;
  m_map = map;
  m_px = px;
  m_py = py;
  m_sizex = sizex;
  m_sizey = sizey;
  m_ui->create_window_empty(m_px, m_py, m_sizex, m_sizey, "windowpic");
  m_img = new Img_container("media/tunnel.img");
  //m_img = new Img_container("img_output.img");
  std::vector<Pixel> p;
  Pixel pix;
  p.resize(m_sizex/2, pix);
  m_grid.resize(m_sizey, p);
//std::cout << "The size is:" << std::endl;
//std::cout << "X: " << m_grid[0].size() << std::endl;
//std::cout << "Y: " << m_grid.size() << std::endl;
//assert(false);
}

Windowpic::~Windowpic(){
  delete m_img;
  delete m_map;
}
void Windowpic::cursorpos(int px, int py){
  ++px;
  ++py;
  std::cout << "\033["<<py<<";"<<px<<"H";
}

void Windowpic::hide_cursor(){
  std::cout << "\033[?25h";
}

void Windowpic::load_image(int px, int py, std::string filename){
  /*
    m_img->init_img(filename);
  //m_img->init_img(filename);
  std::vector<std::vector<Pixel>> grid = m_img->get_img();
  int tx = px + grid[0].size();
  int ty = py +grid.size();
  if(tx >= grid[0].size()) tx = grid[0].size()-1;
  if(ty >= grid.size()) ty = grid.size() -1;
 
  int gy = 0;
  for(int y = py; y != ty; ++y){
    int gx = 0; 
    for(int x = px; x != tx; ++x){
      if(y > 0 && x > 0 && gx < grid[0].size() && gy < grid.size()){
        m_grid[y][x] = grid[gy][gx];
      }
      ++gx;
    }
    ++gy;
  }
  */
  m_img->init_img(filename);
}

void Windowpic::print(int px, int py, int direction, Windowinfo * wininfo){
  choose_image(px, py, direction, wininfo);
  
  std::vector<std::vector<Pixel>> grid = m_img->get_img();
  int sx = m_px+1;
  int sy = m_py+1;
  unsigned int mx = m_sizex/2 -2;
  unsigned int my = m_sizey-3;
  cursorpos(sx, sy);
  for(unsigned int y = 0; y < grid.size(); ++y){
    std::string s = "";
    for(unsigned int x = 0; x < grid[y].size(); ++x){
        s+= grid[y][x].get_str();
    }
    //s+="\033[0m";
    cursorpos(sx, sy);
    sy++;
    
    //m_ui->print_line_at(sx, sy, s, "windowpic");
    std::cout << s;//.length();
    std::cout.flush();
  }
}


void Windowpic::choose_image_split(int px, int py, int dir, Windowinfo * wininfo){
  
  std::vector<std::vector<int>> paths;
  std::vector<int> p = {1};
  paths.push_back(p);
  p = {3};
  paths.push_back(p);
  p = {1, 2};
  paths.push_back(p);
  p = {2};
  paths.push_back(p);
  p = {2,3};
  paths.push_back(p);
  p = {2,2,1};
  paths.push_back(p);
  p = {2,2};
  paths.push_back(p);
  p = {2,2,3};
  paths.push_back(p);
  p = {2,2,2,1};
  paths.push_back(p);
  p = {2,2,2};
  paths.push_back(p);
  p = {2,2,2,3};
  paths.push_back(p);
  std::cout << paths.size() << std::endl;
  assert(paths.size() == 11);
  
  //Now check all of these spaces if they are occupied by a wall or not
  std::vector<bool> space = {false, false, false, false, false, false, false, false, false, false, false};
  //unsigned int spaces = 0;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};  
  int sp = 0;
  for(auto i = paths.begin(); i != paths.end(); ++i){
    int tx = px;
    int ty = py;
    for(auto j = i->begin(); j != i->end(); ++j){
      int temp = dir+(*j);
      if(temp > 3) temp -=4;
      tx += dx[temp];
      ty += dy[temp];
    }
    space[sp] = m_map->space_free(tx, ty);
    ++sp;
  }
 
  
}

void Windowpic::choose_image(int px, int py, int dir, Windowinfo * wininfo){
  /*
    Need to check 11 spaces if they are occupied and set the image thereafter, if this is the same image as the active one to not change. 
    left
    forward left
    forward
    forward right
    right
    forward forward left
    forward forward 
    forward forward right
    forward forward forward left
    forward forward forward
    forward forward forward right
    
    forward = +2;
    left = +1;
    right = +3;
    
    1
    1, 2
    1, 2, 2
    1, 2, 2, 2
    2
    2, 2
    2, 3
    2, 2, 3
    2, 2, 2
    2, 2, 2, 3
    3

    This is a very pretty method to do this.
  */
  
  // Save all possible paths.
  
  std::vector<std::vector<int>> paths;
  std::vector<int> p = {1};
  paths.push_back(p);
  p = {3};
  paths.push_back(p);
  p = {1, 2};
  paths.push_back(p);
  p = {2};
  paths.push_back(p);
  p = {2,3};
  paths.push_back(p);
  p = {2,2,1};
  paths.push_back(p);
  p = {2,2};
  paths.push_back(p);
  p = {2,2,3};
  paths.push_back(p);
  p = {2,2,2,1};
  paths.push_back(p);
  p = {2,2,2};
  paths.push_back(p);
  p = {2,2,2,3};
  paths.push_back(p);
  //  std::cout << paths.size() << std::endl;
  assert(paths.size() == 11);
  
  //Now check all of these spaces if they are occupied by a wall or not
  std::vector<bool> space = {false, false, false, false, false, false, false, false, false, false, false};
  //unsigned int spaces = 0;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};  
  int sp = 0;
  for(auto i = paths.begin(); i != paths.end(); ++i){
    int tx = px;
    int ty = py;
    for(auto j = i->begin(); j != i->end(); ++j){
      int temp = dir+(*j);
      if(temp > 3) temp -=4;
      tx += dx[temp];
      ty += dy[temp];
    }
    space[sp] = m_map->space_free(tx, ty);
    ++sp;
  }
  //Now depending on which set of spaces are occupied we choose the correct image
  /*left
    right
    forward left
    forward
    forward right   
    forward forward left
    forward forward 
    forward forward right
    forward forward forward left
    forward forward forward
    forward forward forward right
     */
  std::string filename = "-1";
  
  
  //Depending on which level forward is shown
  //This assumes that there may not be four open in a square - or more. only corridoors.
  
  if(!space[3]){ // If the first wall is closed
    if(!space[0] && !space[1]){
      filename = "0";
    }
    else if(!space[0] && space[1]){
      filename = "1";
    }
    else if(space[0] && !space[1]){
      filename = "2";
    }
    else if(space[0] && space[1]){
      filename = "3";
    }
  }
  else if(!space[6]){ //If the second wall is closed
    if(!space[2] && !space[4]){
      if(!space[0] && !space[1]){
        filename = "4";
      }
      else if(!space[0] && space[1]){
        filename = "5";
      }
      else if(space[0] && !space[1]){
        filename = "6";
      }
      else if(space[0] && space[1]){
        filename = "7";
      }
    }
    else{
      if(!space[2] && space[4]){
        filename = "8";
      }
      else if(space[2] && !space[4]){
        filename = "9";
      }
      else if(space[2] && space[4]){
        filename = "10";
      }
    }
  }
  else{ // If all open
    if(!space[2] && !space[4]){
      if(!space[0] && !space[1]){
        if(!space[5] && ! space[7]){
          filename = "11";
        }
        else if(space[5] && !space[7]){
          filename = "18";
        }
        else if(!space[5] && space[7]){
          filename = "19";
        }
        else if(space[5] && space[7]){
          filename = "20";
        }
      }
      else{
        if(space[0] && !space[1]){
          filename = "12";
        }
        else if(!space[0] && space[1]){
          filename = "13";
        }
        else if(space[0] && space[1]){
          filename = "14";
        }
      }
    }
    else{
      if(space[2] && !space[4]){
        filename = "15";
      }
      else if(!space[2] && space[4]){
        filename = "16";
      }
      else if(space[2] && space[4]){
        filename = "17";
      }
    }
  }
  
  
  if(filename == "18" || filename == "19" || filename == "20"){
    filename = "11";
  }
  
  if(filename == "-1"){
    std::ofstream file("thing.txt");
    for(int i = 0; i < 11; ++i){
      
      file << space[i] << " ";
    }
    file << "\n";
  }
  assert(filename != "-1");
  if(m_last_picture != filename){
    load_image(0,0,"media/path"+filename+".img");
  }
  m_last_picture = filename;
}
