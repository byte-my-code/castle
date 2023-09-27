#include "renderwindow.h"
#include "game.h"
#include "config.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdexcept>
#include <iostream>


RenderWindow::RenderWindow(u16 width, u16 height, bool fs) {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::runtime_error("couldnt init SDL2");
  }

  window = SDL_CreateWindow(APP_TITLE,
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width, height,
                            SDL_WINDOW_SHOWN);

  if (window == NULL) {

    printf("SDL2 error: %s\n", SDL_GetError());
    throw std::runtime_error("SDL2 CreateWindow error");
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == NULL) {
    printf("SDL2 error: %s\n", SDL_GetError());
    throw std::runtime_error("SDL2 CreateRenderer error");
  }

  width = width;
  height = height;
  fullscreen = fs;
  closed = false;
  
}

RenderWindow::~RenderWindow() {
  std::cout << "Cleaning up SDL2 memory..." << std::endl;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void RenderWindow::update() {

  if (closed) return;

  SDL_Event evt;

  while (SDL_PollEvent(&evt)) {

    if (evt.type == SDL_QUIT) {
      shouldClose();
    }
  }
}

void RenderWindow::refresh() {

  SDL_RenderPresent(renderer);
}

void RenderWindow::setClearColor(u8 r, u8 g, u8 b, u8 a) {

  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void RenderWindow::shouldClose() {

  Game::getInstance()->stopRunning();

}


void RenderWindow::showPointer(bool yesno)    {

  if (yesno) {
    SDL_ShowCursor(SDL_ENABLE);
    pointer = true;
  }
  else {
    SDL_ShowCursor(SDL_DISABLE);
    pointer = false;
  }    
}
