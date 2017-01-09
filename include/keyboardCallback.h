#ifndef KEYBOARDCALLBACK_H
#define KEYBOARDCALLBACK_H

#include <SDL.h>
typedef void (* keyCB) (void);
/** Keyboard CallBack
 * \param pointer to keyCallback callback
 * \param ScanCode for key
 * \param Greater than 1 for keydown
 * \param minKey for callback
 * \param maxKey for callback
 */
struct keyCallback {
    keyCB callback;
    int sc;
    bool keyDown;
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
#endif
