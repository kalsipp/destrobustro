#include "music.hpp"
#include <cassert>


void play(){
  std::ifstream file; 
  file.open("music.txt");
  std::string text;
  getline(file, text);
  file.close();
  system(text.c_str());
}


Music::Music(){
  t =std::thread(play);
  
}


Music::~Music(){
  t.join();
}
