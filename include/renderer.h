#ifndef RENDERER_H
#define RENDERER_H

#include "snake.h"

class Renderer
{
    public:
        /** Default constructor */
        Renderer(Uint32 flags, unsigned int h, unsigned int w, bool f);
        /** Default destructor */
        ~Renderer();

        /** Access m_window
         * \return The current value of m_window
         */
        SDL_Window * Getwindow() { return m_window; }
        /** Set m_window
         * \param val New value to set
         */
        void Setwindow(SDL_Window * val) { m_window = val; }
        /** Access m_renderer
         * \return The current value of m_renderer
         */
        SDL_Renderer * Getrenderer() { return m_renderer; }
        /** Set m_renderer
         * \param val New value to set
         */
        void Setrenderer(SDL_Renderer * val) { m_renderer = val; }
        /** Draw Game */
        void Draw();

    protected:

    private:
        SDL_Window * m_window; //!< Member variable "m_window"
        SDL_Renderer * m_renderer; //!< Member variable "m_renderer"
};

#endif // SDL_H
