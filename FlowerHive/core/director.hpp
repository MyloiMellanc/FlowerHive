//
//  director.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 30..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef director_hpp
#define director_hpp


#include "macro.h"

#include <SDL2/SDL.h>


/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */


////////////////////////////////////////////////////////////////




class Scene;

//// SDL 초기화, 윈도우 생성 및 속성관리

class Director;

class DirectorMethod
{
PROTECT_CONSTRUCTOR_ACCESS:
    DirectorMethod();
    
public:
    virtual bool init(int width, int height) = 0;
    virtual void setWindowSize(int width, int height) = 0;
    virtual Renderer* createRenderer() = 0;
    
    
    
    
    virtual ~DirectorMethod();
    
protected:
    Director* _pDirector;
};



class DirectorMethodSDL : public DirectorMethod
{
public:
    DirectorMethodSDL();
    
    virtual bool init(int width, int height);
    virtual void setWindowSize(int width, int height);
    virtual Renderer* createRenderer();
    
    
    
    virtual ~DirectorMethodSDL();
    
private:
    SDL_Window* _pWindow;
    SDL_Renderer* _pRenderer;
};






class Director
{
PROTECT_CONSTRUCTOR_ACCESS:
    Director();
    
public:
    static Director* getInstance();
    
    ///Method class function
    bool init(int width, int height);       //윈도우를 띄운다.
    void setWindowSize(int width, int height);
    Renderer* createRenderer();
    
    ///
    
    
    
    void run();     //러닝 참으로 한 뒤 루프
    void pause();   //델타 타임을 0로 고정
    void stop();
    
    
    void setScene(Scene* scene);
    

    
    
private:
    static Director* _pInstance;
    
    
    bool _running;
    
    int _window_width;
    int _window_height;
    
    DirectorMethod* _pMethod;
    
    Scene* _pScene;
    
    
};





#endif /* director_hpp */
