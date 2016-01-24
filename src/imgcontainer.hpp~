#ifndef IMGCONTAINER_HPP
#define IMGCONTAINER_HPP

#include <string>
#include <vector>
#include "pixel.hpp"
//#include "gameobject.hpp"
class Gameobject;
class Textbox;
class Img_container{
  friend class Gameobject;
  friend class Textbox;
public:
  Img_container(std::string filename);
  void init_img(std::string s);
  //Img_container();
  const std::vector<std::vector<Pixel>> & get_img()const;
  void set_pixel(const Pixel & p, int px, int py);
private:
  Img_container(); 
  //std::vector<std::vector<std::string>> img_txt;
  std::vector<std::vector<Pixel>> img_txt;
  void img_to_str_vector(std::string filename, std::vector<std::vector<Pixel>> & im_text_ref);
};


#endif
