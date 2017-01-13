#ifndef TYPES_H
#define TYPES_H

#include <SDL.h>
#include <functional>
#include <map>

/** Type Definition for the keyboard callback pointer */
typedef std::function<void(int)> keyCB;

/** Keyboard CallBack
 * \param pointer to keyCallback callback
 * \param ScanCode for key
 * \param If True only returns callback on the first frame of keypress.
 * \param minKey for callback
 * \param maxKey for callback
 */
struct keyCallback {
    keyCB callback;
    int sc = SDL_SCANCODE_UNKNOWN;
    bool keyDown = false;
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
