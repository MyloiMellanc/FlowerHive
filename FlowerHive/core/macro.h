//
//  macro.h
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 23..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef macro_h
#define macro_h

#include "vec2.h"
#include <SDL2/SDL.h>

//부모클래스에 대한 생성자 접근 방지
#define PROTECT_CONSTRUCTOR_ACCESS protected




//SDL_rect 에서 int를 사용하므로, 이에 대한 변경가능성을 생각할것.
typedef int pos_type;
typedef ivec2 Position;
typedef struct scale
{
    scale(int width, int height)
    {
        w = width;
        h = height;
    }
    int w;
    int h;
}Scale;

typedef SDL_Rect Rect;

typedef struct touch_event
{
    int id;
    int x;
    int y;
    int prevX;
    int prevY;
    int deltaX;
    int deltaY;
    int state;
    int tapCount;
}Touch;

typedef SDL_Renderer Renderer;



#endif /* macro_h */
