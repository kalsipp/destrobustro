#ifndef PIXEL_HPP
#define PIXEL_HPP
#include <string>
#include <iostream>
struct Pixel{
  std::string s;
  Pixel();
  Pixel(int _c);
  Pixel(std::string _s);
  std::string get_str() const;
};
#endif
