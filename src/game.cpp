#include "game.h"
#include "renderwindow.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <cstdlib>
#include <exception>
#include <ios>
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

Game *Game::getInstance() {

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

  u32 lastUpdate = SDL_GetTicks();

  while (running) {

    // Process mouse/keyboard events
    window->update();

    // Physics delta time
    u32 current = SDL_GetTicks();
    float dt = (current - lastUpdate) / 1000.0f;

    update(dt);

    lastUpdate = current;

    render();
  }
}

void Game::init() {

  try {
    window = new RenderWindow(800, 600);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }

  window->showPointer(false);

  running = true;
}

void Game::update(float dt) {}

void Game::render() {

  window->setClearColor(0, 0, 0, 255);

  // Draw shit here

  window->refresh();
}

void Game::cleanup() {

  window->showPointer(true);

  // RenderWindow should always be last
  delete window;
  window = nullptr;
}
