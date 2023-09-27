#include "game.h"

int main(int argc, char* argv[]) {

  Game::getInstance()->run();

  Game::destroy();

  return 0;

}
