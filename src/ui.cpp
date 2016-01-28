#include "ui.hpp"
#include <cassert>
Ui::Ui(){
  m_logger = new Logger("Ui");
  m_logger->log("Ui created.");
  initscr(); //Start curses mode
  curs_set(0);
  //start_color();
  //use_default_colors();
  refresh();
  //init_pair(1, COLOR_RED, COLOR_BLUE);
  //attron(COLOR_PAIR(1));
  keypad(stdscr, true); //Get f1, f2 etc..
  cbreak();
  noecho();
  refresh();
}

Ui::~Ui(){
  m_logger->log("Ui deleted.");
  for(auto i = m_windows.begin(); i != m_windows.end(); ++i){
     delwin((*i).second);
  }
  endwin();
  delete m_logger;
}

void Ui::create_window(int px, int py, int sizex, int sizey, std::string id){
  if(m_windows.count(id) != 0){
    wrefresh(m_windows[id]);
    delwin(m_windows[id]);
  }

  WINDOW * win;
  win = newwin(sizey, sizex, py, px);
  scrollok(win, false);
  wrefresh(win);
  m_windows[id] = win;
}

void Ui::create_window_empty(int px, int py, int sizex, int sizey, std::string id){
  if(m_windows.count(id) != 0){
    wrefresh(m_windows[id]);
    delwin(m_windows[id]);
  }
  WINDOW * win;
  win = newwin(sizey, sizex, py, px);
  box(win, 0, 0);
  wrefresh(win);
  m_windows[id] = win;
  scrollok(win, false);
}

void Ui::create_window_scroll(int px, int py, int sizex, int sizey, std::string id){
  if(m_windows.count(id) != 0){
    wrefresh(m_windows[id]);
    delwin(m_windows[id]);
  }
  WINDOW * win;
  win = newwin(sizey, sizex, py, px);
  wrefresh(win);
  scrollok(win, true);
  m_windows[id] = win;
}

void Ui::print_line_at(int px, int py, std::string text, std::string id){
  
  if(m_windows.count(id) != 0){
    m_logger->log("Attemping to print " + text + " at px:" + std::to_string(px)+ " py:"+ std::to_string(py) + ".");
    int k = mvwprintw(m_windows[id], py, px, text.c_str());
    wrefresh(m_windows[id]);
    m_logger->log(std::to_string(k));
  }else{
    m_logger->log("In print_line_at no window named " + id + "found.");
  }
}

void Ui::print_line(std::string text, std::string id){
  if(m_windows.count(id) != 0){
    scroll(m_windows[id]);
  int ymax = 0;
  int xmax = 0;
  getmaxyx(m_windows[id], ymax, xmax);
  mvwprintw(m_windows[id], ymax-1, 0, text.c_str());
  wrefresh(m_windows[id]);
  }else{
    m_logger->log("In print_line, no window named " + id + " found.");
  }
}

void Ui::print_pos(std::string text, std::string id, int px, int py){
  if(m_windows.count(id+m_scrollending) != 0){
    scroll(m_windows[id+m_scrollending]);
    mvwprintw(m_windows[id+m_scrollending], py, px, text.c_str());
    wrefresh(m_windows[id+m_scrollending]);
  }else{
    m_logger->log("No window named " + id);
  }
}


char Ui::get_input(){
  return getch();
}
