#ifndef TEXTGRAPHICS_HPP
#define TEXTGRAPHICS_HPP
#include <vector>
#include <string>
#include <chrono>
#include <climits>
#include <map>
#include "pixel.hpp"
#include "imgcontainer.hpp"
class Textgrafs{
public:
  Textgrafs();
  void add_pixel(const Pixel & p, int px, int py);
  void add_image(const std::vector<std::vector<Pixel>> &, int px, int py);
  void add_image(const Img_container & img, int px, int py);
  void print(); //Prints one grid
  void clear_screen(); //Empty screen
  void hide_cursor();
  void show_cursor();
  void cursorpos(int px, int py); //Set cursorpos on screen
  std::string cursorpos_str(int px, int py);
  void fill_grid(const Pixel & p);
  void clear_grid(); 
  void clear_grid_specific(int px, int py, int sizex, int sizey);
  int rows_;
  int cols_;
private:

  void save_old_grid();
  std::vector<std::vector<std::string>> grid;
  std::vector<std::vector<std::string>> old_grid;
};

#endif
