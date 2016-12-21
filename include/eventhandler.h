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
        /** Gets non keyboard, mouse, and joystick events
         * \return Array of events
         */
        //TODO: bool* GetEvent();
        /** Event Updater */
        void Update();


    protected:

    private:
        /** Handles Quit Events
         * \return Returns true if quit event is found
         */
        bool Close();
        /** Handles Keyboard Events
         * \param Reference to array of keys
         * \return Amount of Keys
         */
        int getKeys();
        Game * m_game; //!< Reference to the game eventhandler is attached to.
};

#endif // EVENTHANDLER_H
