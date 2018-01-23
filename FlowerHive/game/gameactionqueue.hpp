//
//  gameactionqueue.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef gameactionqueue_hpp
#define gameactionqueue_hpp

#include <queue>

class Action;
class Sprite;


typedef struct action_data
{
    Action* _pAction;
    Sprite* _pTarget;
}ActionData;



class GameActionQueue
{
    //세팅
    //배분 ->   (액션 객체 포인터, 대상 객체 포인터)
    
};

#endif /* gameactionqueue_hpp */



/*
 *
 *  다음 액션큐 요청하기 - 서브액션으로 액션큐 포인터를 담는 알림액션 구현하기
 *
 *
 */
