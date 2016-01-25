#include "ui.hpp"
#include <cassert>
Ui::Ui(){
  m_logger = new Logger("Ui");
  m_logger->log("Ui created.");
  initscr(); //Start curses mode
  start_color();
  //use_default_colors();
  refresh();
  //if(!has_colors())assert(false);
  init_pair(1, COLOR_RED, COLOR_BLUE);
  attron(COLOR_PAIR(1));
  
  //int c = colors();
  //m_logger->log("I can support " + std::to_string(c)); 
  //raw(); //Line buffering disabled
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
    if(m_windows.count(id+m_scrollending) != 0){
      wrefresh(m_windows[id+m_scrollending]);
      delwin(m_windows[id + m_scrollending]);
    }
  }
  WINDOW * win;
  win = newwin(sizey, sizex, py, px);
  WINDOW * scrollwin = newwin(sizey-2, sizex-2, py+1, px+1);
  scrollok(scrollwin, true);
  // wrefresh(win);
  m_windows[id+m_scrollending] = scrollwin;
  box(win, 0, 0);
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
}


void Ui::print_line(std::string text, std::string id){
  if(m_windows.count(id+m_scrollending) != 0){
    wbkgd(m_windows[id+m_scrollending], COLOR_PAIR(1));
    scroll(m_windows[id+m_scrollending]);
    int x_max = 0;
    int y_max = 0;
    getmaxyx(m_windows[id+m_scrollending], y_max, x_max);
    m_logger->log(std::to_string(x_max) + " " + std::to_string(y_max));
    int x_min = 0;
    int y_min = 0;
    getbegyx(m_windows[id+m_scrollending], y_min, x_min);
    m_logger->log(std::to_string(x_min) + " " + std::to_string(y_min));
    //wprint(m_window[id]);
    mvwprintw(m_windows[id+m_scrollending], y_max-1, 1, text.c_str());
    wrefresh(m_windows[id+m_scrollending]);
  }else{
    m_logger->log("No window named " + id);
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
