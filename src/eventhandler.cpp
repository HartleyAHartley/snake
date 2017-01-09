#include "eventhandler.h"

#include <iostream>
EventHandler::EventHandler(Game* g){
    m_game = g;
    for(int i=0; i < SDL_NUM_SCANCODES; i++){
        m_keys[i] = false;
        m_keysdown[i] = false;
    }
}

EventHandler::~EventHandler(){}

void EventHandler::Update(){
    SDL_PumpEvents();
    if(Close()){
        m_game->close();
    }
    UpdateKeys();
    SDL_Delay(100);
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

void EventHandler::UpdateKeys(){
    int numOfKeys = SDL_PeepEvents(nullptr, 0, SDL_PEEKEVENT, SDL_KEYDOWN, SDL_KEYDOWN);
    SDL_Event kybdEvents[numOfKeys];
    SDL_PeepEvents(kybdEvents, numOfKeys, SDL_GETEVENT, SDL_KEYDOWN, SDL_KEYDOWN);
    for (int i = 0; i < numOfKeys; i++){
        SendKeyCallback(&kybdEvents[i]);
        if(!kybdEvents[i].key.repeat){
            m_keysdown[kybdEvents[i].key.keysym.scancode] = kybdEvents[i].key.state;
        } else {
            m_keysdown[kybdEvents[i].key.keysym.scancode] = false;
            m_keys[kybdEvents[i].key.keysym.scancode] = kybdEvents[i].key.state;
        }
    }
}

int EventHandler::SendKeyCallback(SDL_Event* e){
    int callbacks = 0;
    for(std::list<keyCallback>::iterator j = keyboardCallbacks.begin(); j != keyboardCallbacks.end(); ++j){
        if((*j) == e){
            (*j).callback();
            callbacks++;
        }
    }
    return callbacks;
}

void EventHandler::RegisterKeyCallback(keyCallback kCB){
    keyboardCallbacks.insert(keyboardCallbacks.end(), kCB);
}
