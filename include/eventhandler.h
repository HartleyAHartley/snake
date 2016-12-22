#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL.h>
#include <game.h>
class Game;

class EventHandler
{
    public:
        /** Default constructor */
        EventHandler(Game* gameObj);
        /** Default destructor */
        ~EventHandler();
        /** Event Updater */
        void Update();


    protected:

    private:
        /** Handles Quit Events
         * \return Returns true if quit event is found
         */
        bool Close();
        /** Handles Keyboard Events */
        void UpdateKeys();
        Game * m_game; //!< Reference to the game eventhandler is attached to.
        bool m_keys[SDL_NUM_SCANCODES];
        bool m_keysdown[SDL_NUM_SCANCODES];

};

#endif // EVENTHANDLER_H
