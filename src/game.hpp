#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <sys/ioctl.h>

#include "logger.hpp"
#include "ui.hpp"
#include "pixel.hpp"
#include "windowinfo.hpp"
#include "windowinv.hpp"
#include "windowpic.hpp"
class Game{
public:
  Game();
  ~Game();
  void mainloop();
private:
  void init();
  Logger * m_logger;
  int m_rows;
  int m_cols;
  int m_colsd;
  Ui * m_ui;
  Windowinfo * m_infowin = nullptr;
  Windowinv * m_invwin = nullptr;
  Windowpic * m_picwin = nullptr;
  
  std::string m_inventoryid = "inventory";
  std::string m_infoid = "info";
};
