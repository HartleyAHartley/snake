#include "game.h"

Game::Game()
{
    m_screenWidth = 630;
    m_screenHeight = 480;
    m_fullscreen = false;
    try {
        m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, m_screenHeight, m_screenWidth, false);
    }
    catch ( const GameError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
        m_initError = true;
    }
    m_eventHandler = new EventHandler(this);
    m_gameBoard = new GameBoard(m_eventHandler, m_renderer);
}

Game::Game(unsigned int w, unsigned int h, bool f)
{
    m_screenWidth = w;
    m_screenHeight = h;
    m_fullscreen = true;

    m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, w, h, false);
    m_gameBoard = new GameBoard(m_eventHandler, m_renderer);
}

Game::~Game()
{
    delete m_renderer;
}

void Game::Draw()
{
    m_renderer->Draw();
}

void Game::Step()
{
    m_eventHandler->Update();
}
