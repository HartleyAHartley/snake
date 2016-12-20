#include "game.h"

Game::Game()
{
    m_screenWidth = 480;
    m_screenHeight = 560;
    m_fullscreen = true;
    m_init = true;
    try {
        m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, 480, 560, false);
    }
    catch ( const GameError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
        m_init = false;
    }
}

Game::Game(unsigned int w, unsigned int h, bool f)
{
    m_screenWidth = w;
    m_screenHeight = h;
    m_fullscreen = true;

    m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, w, h, false);
}

Game::~Game()
{
    delete m_renderer;
}

void Game::Step()
{
    m_renderer->Draw();
}
