#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include <list>
#include <chrono>

#include "renderer.h"
#include "types.h"
#include "eventhandler.h"
#include "Snake.h"
#include "gameboard.h"

class EventHandler;
class Snake;
class GameBoard;

class Game {
public:
    /** Define Width, Height, and Fullscreen
     * \param w Width
     * \param h Height
     * \param f Fullscreen
     */
    Game(unsigned int w=640, unsigned int h=480, bool f=false);
    /** Default destructor */
    ~Game();

    /** Access screenWidth
     * \return The current value of screenWidth
     */
    unsigned int GetscreenWidth() {
        return m_screenWidth;
    }
    /** Set screenWidth
     * \param val New value to set
     */
    void SetscreenWidth(unsigned int val) {
        m_screenWidth = val;
    }
    /** Access screenHeight
     * \return The current value of screenHeight
     */
    unsigned int GetscreenHeight() {
        return m_screenHeight;
    }
    /** Set screenHeight
     * \param val New value to set
     */
    void SetscreenHeight(unsigned int val) {
        m_screenHeight = val;
    }
    /** Access fullscreen
     * \return The current value of fullscreen
     */
    bool Getfullscreen() {
        return m_fullscreen;
    }
    /** Set fullscreen
     * \param val New value to set
     */
    void Setfullscreen(bool val) {
        m_fullscreen = val;
    }
    /** Advance game by a frame */
    void Step();
    /** Check if game started successfully
     * \return The current value of init
     */
    bool InitError() {
        return m_initError;
    }
    /** Check if game should close
     * \return The current value of close
     */
    bool quit() {
        return m_quit;
    }
    /** Sets m_quit to true */
    void close() {
        m_quit = true;
    }
    /** Returns eventHandler
     * \return The pointer to the eventHandler
     */
    EventHandler* GeteventHandler() {
        return m_eventHandler;
    }
    /** Returns renderer
     * \return The pointer to the renderer
     */
    Renderer* Getrenderer() {
        return m_renderer;
    }
    /** Returns GameObject List
     * \return The pointer to the GameObject List
     */
    std::map<std::string, GameObject*>* GetGameObjects() {
        return &m_gameobjects;
    }
    /** Updates Scene */
    void Draw();
    /** Updates the delta time */
    void DTime();
    /** Returns delta time
     * \return dTime
     */
    double getDTime();


protected:

private:
    EventHandler* m_eventHandler; //!< Pointer to eventHandler Object
    Renderer* m_renderer; //!< Member variable "renderer"
    std::map<std::string, GameObject*> m_gameobjects; //!< List of GameObjects
    unsigned int m_screenWidth; //!< Member variable "screenWidth"
    unsigned int m_screenHeight; //!< Member variable "screenHeight"
    bool m_fullscreen; //!< Member variable "fullscreen"
    bool m_initError = false; //!< Member variable "init" True if game init was successful.
    bool m_quit = false; //!< Member variable "open" True if game should stay open.
    std::chrono::duration<double> dTime;
    Time lastFrame;

};

#endif // GAME_H
