#ifndef RENDERWINDOW_H_INCLUDED
#define RENDERWINDOW_H_INCLUDED

#include "config.h"
#include <SDL2/SDL.h>



/**
 * RenderWindow is the screen target for the application
 * It is responsible for handling its own events.
 **/
class RenderWindow {

public:

  RenderWindow(u16 width, u16 height, bool fs=false);
  ~RenderWindow();

  void update();

  void refresh();
  void setClearColor(u8 r, u8 g, u8 b, u8 a=255);

  bool isClosed() { return closed; }

  void shouldClose();
  
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  u16 width;
  u16 height;
  bool fullscreen {false};
  bool closed {true}; 
  
  
};

#endif
