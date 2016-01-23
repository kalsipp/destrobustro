#include "ui.hpp"

Ui::Ui(){
  m_logger = new Logger("Ui");
  m_logger->log("Ui created.");
  initscr(); //Start curses mode 
  raw(); //Line buffering disabled
  keypad(stdscr, true); //Get f1, f2 etc..
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
  box(win, 0, 0);
  wrefresh(win);
  m_windows[id] = win;
}

void Ui::print_window(std::string text, std::string id){
  if(m_windows.count(id) != 0){
    wprintw(m_windows[id], text.c_str());
    wrefresh(m_windows[id]);
  }else{
    m_logger->log("No window named " + id);
  }
}

char Ui::get_input(){
  return getch();
}
