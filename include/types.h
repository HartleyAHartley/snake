#ifndef TYPES_H
#define TYPES_H

#include <SDL.h>

/** Type Definition for the keyboard callback pointer */
typedef void (* keyCB) (uint64_t rbxRegister);

/** Keyboard CallBack
 * \param pointer to keyCallback callback
 * \param ScanCode for key
 * \param Greater than 1 for keydown
 * \param minKey for callback
 * \param maxKey for callback
 */
struct keyCallback {
    keyCB callback;
    int sc = SDL_SCANCODE_UNKNOWN;
    uint64_t rbxRegister;
    bool keyDown = false;
    bool operator==(const SDL_Event* e) const {
        if(sc == e->key.keysym.scancode){
            if(e->key.repeat == 0){
                return true;
            } else if(keyDown){
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
};

struct renderRect {
    SDL_Rect rect;
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 255;
    bool render = true;
};

#endif
