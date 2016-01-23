#include "game.hpp"

Game::Game(){
  m_logger = new Logger("game");
  m_logger->log("Main gameloop created.");
  m_ui = new Ui();
}

Game::~Game(){
  delete m_logger;
  delete m_ui;
}
void Game::mainloop(){
  m_logger->log("Running mainloop.");
  bool game_running = true;
  m_ui->create_window(0, 0, 20, 20, "thing");
  m_ui->print_window("Hello", "thing");
  while(game_running){
    
    char input =  m_ui->get_input();

    if(input == 'q') break; //If all else fails

    m_logger->log("Raw input: " + input);
    
    input = tolower(input);

    m_logger->log("Tolower input " + input);

    if(input == 10 || input == KEY_F(2)){
      game_running = false;
    }else if(input == 'w'){
      std::cout << "HELL YES" << std::endl;
    }else if(input == 'W'){
      std::cout << "BIG YES" << std::endl;
    }
    
  }

  m_logger->log("Mainloop done.");
}
