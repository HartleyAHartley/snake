#include "renderer.h"

Renderer::Renderer(Uint32 flags, unsigned int h, unsigned int w, bool f) {
    if ( SDL_Init( flags ) != 0 )
        throw GameError();

    if ( SDL_CreateWindowAndRenderer( w, h, SDL_WINDOW_SHOWN,
                                      &m_window, &m_renderer ) != 0 )
        throw GameError();
}

Renderer::~Renderer() {
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void Renderer::Draw() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear( m_renderer );
    // Show the window
    for(std::list<renderRect*>::iterator i = renderRectangles.begin(); i != renderRectangles.end(); ++i) {
        if((*i)->render) {
            RenderRect((*i));
        }
    }
    SDL_RenderPresent( m_renderer );
}

bool Renderer::RenderRect(const renderRect * rr) {
    if(SDL_SetRenderDrawColor(m_renderer, rr->r, rr->g, rr->b, rr->a)) {
        return false;
    } else {
        if(SDL_RenderFillRect(m_renderer, &rr->rect)) {
            return false;
        }
    }
    return true;
}


const std::list<renderRect*>::iterator Renderer::AddRectangle(renderRect * rr) {
    return renderRectangles.insert(renderRectangles.end(), rr);
    //TODO: At some point this should return some kind of a reference so that the rectangle can be removed from the list later.
}
