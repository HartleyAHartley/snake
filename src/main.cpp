#include "main.h"

int main( int argc, char * argv[] ) {
    Game * snake = new Game();
    if(snake->InitError()) {
        return 1;
    }
    while(!snake->quit()) {
        snake->Step();
        snake->Draw();
    }
    return 0;
}
