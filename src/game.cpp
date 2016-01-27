#include "game.hpp"
#include <cassert>
Game::Game(){
  m_logger = new Logger("game");
  m_logger->log("Main gameloop created.");
  m_ui = new Ui();
}

Game::~Game(){
  m_logger->log("Main gameloop killed.");
  delete m_logger;
  delete m_ui;
}

void Game::init(){
  m_logger->log("Running init");
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  m_rows = w.ws_row;
  m_cols = w.ws_col;
  m_colsd = w.ws_col*0.5f;
  m_ui->create_window_empty(0, 0, m_cols, m_rows, "outer"); 
  
  int mmsizey = 20;
  int mmsizex = 40;
  int mmpy = 1;
  int mmpx = m_cols - mmsizex-2;
  m_ui->create_window_empty(mmpx, mmpy, mmsizex, mmsizey, "minimap");
  m_ui->print_line_at(1, 1,"Minimap", "minimap");


  int invsizey = 8;
  int invpy = m_rows-invsizey-1;
  int invpx = 2;
  int invsizex = m_cols-6;

  m_invwin = new Windowinv(m_ui, invpx, invpy, invsizex, invsizey);


  int infosizex = 40; 
  int infopx = m_cols-infosizex-2;
  int infopy = mmpy+mmsizey;
  int infosizey = m_rows-1-infopy-invsizey;  
  m_infowin = new Windowinfo(m_ui, infopx, infopy, infosizex, infosizey);
  
  int imagepx = 2;
  int imagepy = 1;
  int imagesizex = m_cols-infosizex-6;
  int imagesizey = m_rows-invsizey-2;
  m_picwin = new Windowpic(m_ui, imagepx, imagepy, imagesizex, imagesizey);
  m_picwin->print();
  //m_ui->create_window(imagepx, imagepy, imagesizex, imagesizey, "image");
  m_logger->log("init done");
}

void Game::mainloop(){
  m_logger->log("Running mainloop.");
  init();
  int counter = 0;
  bool game_running = true;
  while(game_running){
    char input =  m_ui->get_input();
    if(input == 'p') break; //If all else fails

    m_logger->log("Raw input: " + input);
    input = tolower(input);
    m_logger->log("Tolower input " + input);

    if(input == 'q' ){
        game_running = false;
    }else if(input == 'w'){
      m_infowin->print("Walking forward");
    }else if(input == 's'){
      m_infowin->print("Walking backward");
    }else if(input == 'd'){
      m_infowin->print("Walking right");
    }else if(input == 'a'){
      m_infowin->print("Walking left");
    }

    //m_ui->print_line("Inventory here", m_inventoryid);
    //m_ui->print_line("Info here", m_infoid);
    
  }

  m_logger->log("Mainloop done.");
}
