#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

#include "logger.hpp"
#include "ui.hpp"
#include "pixel.hpp"
class Game{
public:
Game();
~Game();
void mainloop();
private:
Logger * m_logger;
Ui * m_ui;
};
