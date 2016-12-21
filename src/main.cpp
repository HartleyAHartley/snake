#include "main.h"

int main( int argc, char * argv[] )
{
        Game * snake = new Game();
        if(snake->InitError()){
            return 1;
        }
        snake->Draw();
        while(!snake->quit()){
            snake->Step();
        }
        return 0;
}
