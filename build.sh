cxxflags="-I./include -I/usr/include/SDL2 -D_REENTRANT -g -DDEBUG -std=c++17"
ldflags="-lSDL2 -lpthread"

g++ -c $cxxflags src/renderwindow.cpp
g++ -c $cxxflags src/game.cpp
g++ -c $cxxflags src/main.cpp

g++ *.o -o Castle $ldflags
