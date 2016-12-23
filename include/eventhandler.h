#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL.h>
#include <list>
#include <game.h>

typedef void (* keyCB) (void);
class Game;
/** Keyboard CallBack
 * \param pointer to keyCallback callback
 * \param ScanCode for key
 * \param True if keydown
 * \param minKey for callback
 * \param maxKey for callback
 */
struct keyCallback {
    keyCB callback,
    int sc,
    int keyDown,
    int minKey,
    int maxKey
};

class EventHandler
{
    public:
        /** Default constructor */
        EventHandler(Game* gameObj);
        /** Default destructor */
        ~EventHandler();
        /** Event Updater */
        void Update();
        /** Add Keyboard CallBack
         * \param reference to keyCallback struct
         * \return Number of successful Callbacks registered
         */
        int RegisterKeyCallback(keyCallback kCB);


    protected:

    private:
        /** Handles Quit Events
         * \return Returns true if quit event is found
         */
        bool Close();
        /** Handles Keyboard Events */
        void UpdateKeys();
        Game * m_game; //!< Reference to the game eventhandler is attached to.
        bool m_keys[SDL_NUM_SCANCODES]; //!< Scancode keys that are held down.
        bool m_keysdown[SDL_NUM_SCANCODES]; //!< Scancode keys that are pressed (First Frame Only).
        std::list<keyCallback> keyboardCallbacks; //!< List of callbacks to the keyboard.

};

#endif // EVENTHANDLER_H
