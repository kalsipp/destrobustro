#ifndef TEXTGRAPHICS_HPP
#define TEXTGRAPHICS_HPP
#include <vector>
#include <string>
#include <chrono>
#include <climits>
#include <map>
#include "pixel.hpp"
#include "gameobject.hpp"
#include "imgcontainer.hpp"
class Textgrafs{
public:
  Textgrafs();

  void add_border(const Pixel & p, int px, int py, int sizex, int sizey);
  void add_pixel(const Pixel & p, int px, int py);
  //void add_image(std::vector<std::vector<std::string>> & , int px, int py);
  void add_image(const std::vector<std::vector<Pixel>> &, int px, int py);
  void add_image(const Img_container & img, int px, int py);
  void add_rect(const Pixel & p, int px, int py, int sizex, int sizey);
  void add_fill(const Pixel & p, int px, int py, int sizex, int sizey);
  void add_fill(int px, int py, int sizex, int sizey);
  //WIP Should textgrafs hold gameobjects?
  void add_gameobject(const Gameobject & g);
  void add_gameobjects(const std::vector<Gameobject> & g);
  //void remove_gameobject; How should I 
  void print(); //Prints one grid
  bool next_tick(); //Should be private
  void paint(); //For continuous animation
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
  std::chrono::system_clock::time_point timer_;
  bool debug = false;
  double time_between_frames_ = 0.005;
  std::vector<std::vector<std::string>> grid;
  std::vector<std::vector<std::string>> old_grid;
  std::map<int, Gameobject> objects;
};

#endif
