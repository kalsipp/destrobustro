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
void Game::mainloop(){
  m_logger->log("Running mainloop.");
  bool game_running = true;
  m_ui->create_window(10, 10, 20, 20, "thing");
  Pixel pix(214);
  
  for(int i = 0; i < 2550; ++i){
    Pixel pix(i);
    std::cout<<i << " "<<pix.get_str()<<std::endl;
    getch();
  }
  
  //m_ui->create_window(10, 10, 20, 20, "that");
  for(int i = 0; i < 100; ++i){
    m_ui->print_line("Helloölkajsdöl", "thing");
  }
  m_ui->print_line(pix.get_str(), "thing");
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
    
  }

  m_logger->log("Mainloop done.");
}
