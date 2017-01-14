#include "game.h"

Game::Game(unsigned int w, unsigned int h, bool f) {
    m_screenWidth = w;
    m_screenHeight = h;
    m_fullscreen = f;

    try {
        m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, m_screenHeight, m_screenWidth, m_fullscreen);
    } catch ( const GameError & err ) {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
        m_initError = true;
    }
    m_eventHandler = new EventHandler(this);
    m_gameobjects.insert( m_gameobjects.end(), new Snake(this));
    m_gameobjects.insert( m_gameobjects.end(), new GameBoard(this));
}

Game::~Game() {
    delete m_renderer;
    delete m_eventHandler;
}

void Game::Draw() {
    m_renderer->Draw();
}

void Game::Step() {
    m_eventHandler->Update();
}
