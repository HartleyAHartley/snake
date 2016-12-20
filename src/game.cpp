#include "game.h"

Game::Game()
{
    m_screenWidth = 480;
    m_screenHeight = 560;
    m_fullscreen = true;

    m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, 480, 560, false);
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
