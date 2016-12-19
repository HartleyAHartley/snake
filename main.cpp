#include "snake.h"

int main( int argc, char * argv[] )
{
    try
    {
        Game * snake = new Game();
        snake->Step();

        return 0;
    }
    catch ( const InitError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }

    return 1;
}
