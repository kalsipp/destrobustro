#include <ncurses.h>
//#include <vector>
//#include <string>
#include <map>
#include "logger.hpp"

class Ui{
public:
  Ui();
  ~Ui();
  char get_input();
  void create_window(int px, int py, int sizex, int sizey, std::string id);
  void print_window(std::string text, std::string id);
private:
  Logger * m_logger;
  std::map<std::string, WINDOW*> m_windows;
};
