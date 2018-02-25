//
//  main.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 10..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>


#include "gameheader.hpp"


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
    
};



int main(int argc, const char * argv[]) {
    
    if(MethodFactory::getInstance()->init() == false)
        return 0;
    
    if(Director::getInstance()->init(800, 600) == false)
        return 0;
    
    Renderer* renderer = Director::getInstance()->createRenderer();
    
    Demp* a = new Demp(renderer, "sample.bmp");
    a->setFrame(50, 50, 100, 100);
    
    
    Layer* layer = new Layer();
    
    Scene* scene = new Scene(renderer);
    
    
    /*TTF_Init();*/
    
    
    SpriteAction* act = new MoveTo({200,200}, 100.0);
    a->addAction(act);
    act->run();
    
    
    
    layer->addSprite(a);
    scene->setLayer(layer);
    Director::getInstance()->setScene(scene);
    
    
    Director::getInstance()->run();
    
    
    
    MethodFactory::getInstance()->deinit();
    
    
    //SDL_SetRenderDrawColor(renderer, 255, 255, 0, 100);
    //SDL_RenderClear(renderer);
    
    
    
        
        
        
        
        //SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
        //SDL_UpdateWindowSurface(gWindow);

    /*
    
    bool running = true;
    while(running)
    {
        //SDL_RenderClear(renderer);
        
        //a->update(0.1);
        //a->render();
        
        
        //SDL_RenderPresent(renderer);
        
        
        
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
    }*/
    
    
    //SDL_Quit();
    
    //TTF_Quit();
    
    return 0;
}







