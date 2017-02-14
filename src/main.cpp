#include "main.h"

int main( int argc, char * argv[] ) {
    Game * snake = new Game(20,0.1f);
    if(snake->InitError()) {
        return 1;
    }
    while(!snake->quit()) {
        snake->Step();
        snake->Draw();
        snake->DTime();
    }
    return 0;
}
