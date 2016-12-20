#include "main.h"

int main( int argc, char * argv[] )
{
        Game * snake = new Game();
        if(snake->getinit()){
            snake->Step();
            return 0;
        }
        return 1;
}
