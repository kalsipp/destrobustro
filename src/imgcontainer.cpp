//A class container for ascii images
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <streambuf>
#include "imgcontainer.hpp"  

Img_container::Img_container(std::string filename){
  img_to_str_vector(filename, img_txt);
}
void Img_container::init_img(std::string filename){
  img_to_str_vector(filename, img_txt);
  // std::cout << img_txt.size() << std::endl;
  //std::cout << img_txt[0].size() << std::endl;
  //std::cout << img_txt[10][0].get_str() << std::endl;
}
const std::vector<std::vector<Pixel>> & Img_container::get_img()const{
  return img_txt;
}
Img_container::Img_container(){}
void Img_container::set_pixel(const Pixel & p, int px, int py){
  if(py < 0 || py >= (int)img_txt.size()) return;
  if(px < 0 || px >= (int)img_txt[py].size()) return;
  img_txt[py][px] = p;
}

void Img_container::img_to_str_vector(std::string filename, std::vector<std::vector<Pixel>> & im_text_ref){
  if(im_text_ref.size() > 0)im_text_ref[0].resize(0);
  im_text_ref.resize(0);
  std::ifstream file(filename.c_str());
  if(file == 0)return;
  std::vector<Pixel> tempvec;
  std::string tempstr;
  while(std::getline(file, tempstr)){
    std::vector<Pixel> tempvec;
    while(tempstr.length() > 12){ // > smallest length TODO
      //Go through this row, chop it up into induvidual "pixels" and add them to their proper place in the vectorvector
      std::string s;
      while(tempstr[0] != '@'){
        if(tempstr[0] != '\n')s+= tempstr[0];
        if(tempstr.length() == 0) break;
        tempstr.erase(tempstr.begin());
      }
      Pixel p(s);
      tempvec.push_back(p);
      //As the strings may be of different length, the letter @ has been added to separate them. (\033 is difficult to compare)
      if(tempstr[0] == '@')tempstr.erase(tempstr.begin());
    }
    for(int i = 0; i < (int)tempstr.length() ; ++i){
      if(tempstr[i] == '\n') tempstr.erase(i); 
    }
    //tempvec.push_back(tempstr);
    im_text_ref.push_back(tempvec);
  } 
  file.close();
}
