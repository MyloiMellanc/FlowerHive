//
//  main.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 10..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>




#include "core/sprite.hpp"
#include "core/action.hpp"


/*
 *
 *  Data 객체는 서버에서 사용하기 위한 것
 *
 *  1. 다만, 스프라이트 적용하는 객체의 구분을 더욱 확실히 할 것. - 주요사항 : board, player, state는 스프라이트를 적용? -> 하지말자! 하나밖에 없는데 왜 해?
 *                                                                          -> 걔네는 Game에서 관리될 것
 *
 *  -> 확정 : 스프라이트 객체는 '단일' 오브젝트에 대한 렌더링 속성 지원을 목적으로 한다.
 *
 *
 *  2. 부모 클래스의 인터페이스는 중요해요. 왜냐하면 다른 클래스에서 쓸 거거든요!
 *      -> 그 떄 코딩에 문제가 있다는 건, 인터페이스가 문제가 있다는 거에요!
 *
 *  3. 모든 외부객체 명령은 인접한 객체에 한한다!
 *  예 ) 인벤토리가 현재 비료상태를 알고싶다면, 상사인 Player에게 연락해라!
 *
 *
 *
 ******** 모든 객체 생성의 기준 : 재사용성, 유지보수, 해당 객체 사용의 간편함 증대
 *
 *
 *  4. 타일 과 같은 스프라이트 기반 객체는 생성 후 데이터를 붙이는 것으로 과정을 간략화 시켜아햐며, 둘 사이의 연관을 최대한 없앤다.
 *
 *  5. 각 클래스의 소멸자에서 제거해야할 속성은 자신의 하위객체들로 한정한다.
 */



/// 객체 참조는 const * , 구조체는 const &을 사용, 일단 이렇게 고정.


//윈도우는 단일 윈도우이며, Scene은 하나씩 사용하는 것으로 확정하고 진행.


class Demp : public Sprite
{
public:
    Demp(Renderer* ren, const char* name)
    : Sprite(ren,name)
    {
        
    }
    /*virtual void update(float dt)
    {
        
    }*/
    virtual void touched(const Touch& touch)
    {
        
    }
    
    virtual void render()
    {
        drawTextureWithRect();
    }
};



int main(int argc, const char * argv[]) {
    
    
    //TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* gWindow = nullptr;
    
    
    //해당 코드는 이 게임이 단일 윈도우를 갖고있는 것을 확정시킨다. - 윈도우 객체 자체에 렌더러를 등록시켜야 한다. (프로그램 진행 중 변동될 일이 없다.)
    gWindow = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    
    //사용이 간단하므로 일단 완성.
    Demp* a = new Demp(renderer, "sample.bmp");
    a->setRect(0, 0, 100, 100);
    
    SpriteAction* act = new MoveTo({200,200}, 100.0);
    a->addAction(act);
    act->run();
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 100);
    SDL_RenderClear(renderer);
    
    
    
        
        
        
        
        //SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
        //SDL_UpdateWindowSurface(gWindow);

    
    
    bool running = true;
    while(running)
    {
        SDL_RenderClear(renderer);
        
        a->update(0.1);
        a->render();
        
        
        SDL_RenderPresent(renderer);
        
        
        
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                    
            }
            
        }
    }
    
    delete a;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);
    
    SDL_Quit();
    
    //TTF_Quit();
    
    return 0;
}







