#include "game.h"
#include "renderwindow.h"

#include <SDL2/SDL.h>
#include <cstdlib>
#include <exception>
#include <iostream>

#ifdef DEBUG_BUILD
void print_verinfo() {

  std::cout << APP_TITLE << std::endl;
  std::cout << "RUNNING IN DEBUG MODE" << std::endl;
#ifdef PLATFORM_LINUX
  std::cout << "Linux Build 0.1" << std::endl;
#endif
}
#else
void print_verinfo() {}
#endif



Game *Game::spInstance = nullptr;


Game* Game::getInstance() {

  if (spInstance == nullptr)
    spInstance = new Game();

  return spInstance;
}


void Game::destroy() {

  if (spInstance)
    delete spInstance;

  spInstance = nullptr;
}


Game::Game() {}

Game::~Game() {

  // Cleanup memory etc...
  cleanup();
}

void Game::run() {

#ifdef DEBUG_BUILD
  print_verinfo();
#endif
  

  // init the application
  init();

  while (running) {

    update();

    render();

    SDL_Delay(10);
  }
}

void Game::init() {

  try {
    window = new RenderWindow(800, 600);
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }  

  running = true;
}

void Game::update() {

  window->update();
  
}

void Game::render() {

  window->setClearColor(0, 0, 0, 255);

  // Draw shit here

  window->refresh();
}

void Game::cleanup() {

  // RenderWindow should always be last
  delete window;
  window = nullptr;
}
