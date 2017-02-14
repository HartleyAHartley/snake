#include "game.h"

Game::Game(int g, float t, unsigned int w, unsigned int h, bool f) {
    lastFrame = Clock::now();
    m_screenWidth = w;
    m_screenHeight = h;
    m_fullscreen = f;
    m_grid = g;
    timeScale = t;

    try {
        m_renderer = new Renderer( SDL_INIT_VIDEO | SDL_INIT_TIMER, m_screenHeight, m_screenWidth, m_fullscreen);
    } catch ( const GameError & err ) {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
        m_initError = true;
    }
    m_eventHandler = new EventHandler(this);
    m_gameobjects["snake"] = new Snake(this);
    m_gameobjects["gameBoard"] = new GameBoard(this);
    m_gameobjects["fruit"] = new Fruit(this);

    m_KeyCB.callback = std::bind(&close, this);
    m_KeyCB.keyDown = true;
    m_KeyCB.sc = SDL_SCANCODE_Q;
    GeteventHandler()->RegisterKeyCallback(&m_KeyCB);
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
    m_gameobjects["snake"]->Update();
}

void Game::DTime(){
    dTime = Clock::now() - lastFrame;
    dTime *= timeScale;
    lastFrame = Clock::now();
}
