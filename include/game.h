#ifndef GAME_H
#define GAME_H

#include <SDL.h>

class Renderer;
#include "renderer.h"
class EventHandler;
#include "eventhandler.h"
#include <iostream>


class Game
{
    public:
        /** Default constructor */
        Game();
        /** Define Width, Height, and Fullscreen
         * \param w Width
         * \param h Height
         * \param f Fullscreen
         */
        Game(unsigned int w, unsigned int h, bool f);
        /** Default destructor */
        ~Game();

        /** Access screenWidth
         * \return The current value of screenWidth
         */
        unsigned int GetscreenWidth() { return m_screenWidth; }
        /** Set screenWidth
         * \param val New value to set
         */
        void SetscreenWidth(unsigned int val) { m_screenWidth = val; }
        /** Access screenHeight
         * \return The current value of screenHeight
         */
        unsigned int GetscreenHeight() { return m_screenHeight; }
        /** Set screenHeight
         * \param val New value to set
         */
        void SetscreenHeight(unsigned int val) { m_screenHeight = val; }
        /** Access fullscreen
         * \return The current value of fullscreen
         */
        bool Getfullscreen() { return m_fullscreen; }
        /** Set fullscreen
         * \param val New value to set
         */
        void Setfullscreen(bool val) { m_fullscreen = val; }
        /** Advance game by a frame */
        void Step();
        /** Check if game started successfully
         * \return The current value of init
         */
        bool InitError() { return m_initError; }
        /** Check if game should close
         * \return The current value of close
         */
        bool quit() { return m_quit; }
        /** Sets m_quit to true */
        void close() { m_quit = true; }

        void Draw();

    protected:

    private:
        EventHandler* m_eventHandler; //!< Pointer to eventHandler Object
        Renderer* m_renderer; //!< Member variable "renderer"
        unsigned int m_screenWidth; //!< Member variable "screenWidth"
        unsigned int m_screenHeight; //!< Member variable "screenHeight"
        bool m_fullscreen; //!< Member variable "fullscreen"
        bool m_initError = false; //!< Member variable "init" True if game init was successful.
        bool m_quit = false; //!< Member variable "open" True if game should stay open.
};

#endif // GAME_H
