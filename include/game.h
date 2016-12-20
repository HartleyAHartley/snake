#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "renderer.h"

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

    protected:

    private:
        Renderer * m_renderer; //!< Member variable "renderer"
        unsigned int m_screenWidth; //!< Member variable "screenWidth"
        unsigned int m_screenHeight; //!< Member variable "screenHeight"
        bool m_fullscreen; //!< Member variable "fullscreen"
};

#endif // GAME_H
