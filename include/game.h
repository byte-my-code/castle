#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "config.h"

class RenderWindow;

class Game {

public:
  static Game *getInstance();
  static void destroy();

  // No copying you fucker!
  Game(const Game&) = delete;
  Game& operator=(Game&) = delete;

  void run();

  bool isRunning() { return running; }
  void stopRunning() { running  = false; }

private:
  Game();
  ~Game();

  void init();

  void update(float dt);
  void render();

  void cleanup();

  static Game *spInstance;
  RenderWindow* window;
  bool running {false};
};

#endif
