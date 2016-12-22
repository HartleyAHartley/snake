#include "eventhandler.h"

#include <iostream>
EventHandler::EventHandler(Game* g){
    m_game = g;
}

EventHandler::~EventHandler(){}

void EventHandler::Update(){
    SDL_PumpEvents();
    if(Close()){
        m_game->close();
    }
    UpdateKeys();
}

bool EventHandler::Close(){
    SDL_Event e;
    if(SDL_PeepEvents(&e, 1, SDL_GETEVENT, SDL_QUIT, SDL_QUIT)){
        if (e.type == SDL_QUIT) {
            return true;
        }
    }
    return false;
}

void EventHandler::GetKeys(){
    int numOfKeys = SDL_PeepEvents(nullptr, 0, SDL_PEEKEVENT, SDL_KEYDOWN, SDL_KEYUP);
    SDL_Event kybdEvents[numOfKeys];
    SDL_PeepEvents(kybdEvents, numOfKeys, SDL_GETEVENT, SDL_KEYDOWN, SDL_KEYUP);
    for (int i = numOfKeys; i >= 0; i--){
        if(!kybdEvents[i].key.repeat){
            m_keysdown[kybdEvents[i].key.keysym.scancode] = kybdEvents[i].key.state;
        } else {
            m_keysdown[kybdEvents[i].key.keysym.scancode] = false;
            m_keys[kybdEvents[i].key.keysym.scancode] = kybdEvents[i].key.state;
        }
    }
}
