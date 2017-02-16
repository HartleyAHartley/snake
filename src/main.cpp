#include "main.h"
#include <iostream>
#include <fstream>

const char configStr[] = "GRIDSIZE=10\nTIMESCALE=1\nWIDTH=640\nHEIGHT=480\nFULLSCREEN=0\nFRUITREWARD=4\n";

int main( int argc, char * argv[] ) {
    int gridSize = 10;
    float timeScale = 1;
    int width = 640;
    int height = 480;
    bool fullscreen = 0;
    int fruitReward = 4;
    std::ifstream config("config.ini", std::fstream::in);
    std::string line="";
    if(config.is_open()){
        while(config.good()){
            getline(config,line);
            int equalPos = line.find("=");
            std::string option="";
            option = line.substr(0,equalPos);
            if(option=="GRIDSIZE"){
                gridSize = stoi(line.substr(equalPos+1));
            } else if(option=="TIMESCALE"){
                timeScale = stof(line.substr(equalPos+1));
            } else if(option=="WIDTH"){
                width = stoi(line.substr(equalPos+1));
            } else if(option=="HEIGHT"){
                height = stoi(line.substr(equalPos+1));
            } else if(option=="FULLSCREEN"){
                fullscreen = stoi(line.substr(equalPos+1));
            } else if(option=="FRUITREWARD"){
                fruitReward = stoi(line.substr(equalPos+1));
            }
        }
        config.close();
    } else {
        std::ofstream config("config.ini", std::fstream::out);
        config << configStr;
        config.close();
    }

    Game * snake = new Game(gridSize,timeScale,width,height,fullscreen,fruitReward);
    if(snake->InitError()) {
        return 1;
    }
    while(!snake->quit()) {
        snake->Step();
        snake->Draw();
        snake->DTime();
    }
    return 0;
}
