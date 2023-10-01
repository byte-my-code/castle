cxxflags="-I./include -I/usr/include/SDL2 -D_REENTRANT -g -DDEBUG -std=c++17"
ldflags="-lSDL2 -lpthread"

if [ -f Castle ]; then
    rm Castle
fi

echo Building program...

g++ -c $cxxflags src/renderwindow.cpp -o build/renderwindow.o
g++ -c $cxxflags src/game.cpp -o build/game.o
g++ -c $cxxflags src/main.cpp -o build/main.o

g++ build/*.o -o Castle $ldflags


if [ -f Castle ]; then
    ./Castle
fi
