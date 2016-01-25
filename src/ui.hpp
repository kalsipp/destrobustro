#include <ncurses.h>
#include <map>
#include "logger.hpp"

class Ui{
public:
  Ui();
  ~Ui();
  char get_input();
  void create_window(int px, int py, int sizex, int sizey, std::string id);
  void create_window_empty(int px, int py, int sizex, int sizey, std::string id);
  void print_line(std::string text, std::string id);
  void print_pos(std::string text, std::string id, int px, int py);
private:
  Logger * m_logger;
  std::map<std::string, WINDOW*> m_windows;
  const std::string m_scrollending = "SCROLL";
};
