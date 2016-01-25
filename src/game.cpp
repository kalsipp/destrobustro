#include "game.hpp"

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
  int infosizey = 8;
  int infopy = m_rows-infosizey-1;
  int infopx = 2;
  int infosizex = m_cols-4;
  m_ui->create_window(infopx, infopy, infosizex, infosizey, m_infoid);

  int inventorysizex = 20; 
  int inventorypx = m_cols-inventorysizex-2;
  int inventorypy = 1;
  int inventorysizey = m_rows-infosizey-2;
  m_ui->create_window(inventorypx, inventorypy, inventorysizex, inventorysizey, m_inventoryid);
  int imagepx = 2;
  int imagepy = 1;
  int imagesizex = m_cols-inventorysizex-6;
  int imagesizey = m_rows-infosizey-2;
  m_ui->create_window(imagepx, imagepy, imagesizex, imagesizey, "image");
  m_logger->log("init done");
}

void Game::mainloop(){
  m_logger->log("Running mainloop.");
  init();
  
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
      std::cout << "HELL YES" << std::endl;
    }else if(input == 'W'){
      std::cout << "BIG YES" << std::endl;
    }

    m_ui->print_line("Inventory here", m_inventoryid);
    m_ui->print_line("Info here", m_infoid);
    
  }

  m_logger->log("Mainloop done.");
}
