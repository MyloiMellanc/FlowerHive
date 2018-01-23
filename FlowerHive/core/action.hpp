//
//  action.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef action_hpp
#define action_hpp

#include "vec2.h"
#include "macro.h"


class Sprite;
class Layer;


class Action
{
PROTECT_CONSTRUCTOR_ACCESS:
    Action();
    
public:
    virtual ~Action();
    
    bool isRunning() const;
    bool isFinished() const;
    
    void run();
    
    virtual void update(float dt) = 0;
    
protected:
    void finish();
    
private:
    bool _running;
    bool _finished;
    
};


class TimerAction : public Action
{
public:
    TimerAction(float time);
    
    ~TimerAction();
    
    void setGoal(float goal);
    float getGoalTime() const;
    float getCurrentTime() const;
    float getGoalPercentage() const;
    
    
    virtual void update(float dt);
    
private:
    float _current;
    float _goal;
};




class SpriteAction : public Action
{
PROTECT_CONSTRUCTOR_ACCESS:
    SpriteAction();
    SpriteAction(Sprite* sprite);
    
public:
    virtual ~SpriteAction();
    
    virtual void setSprite(Sprite* sprite) = 0;
    Sprite* getTargetSprite();
    
    virtual void update(float dt) = 0;
    
    
protected:
    Sprite* _pTarget;
};


class MoveTo : public SpriteAction
{
public:
    MoveTo(Position position, float time);
    MoveTo(Sprite* sprite, Position position, float time);

    
    
    virtual ~MoveTo();
    
    virtual void setSprite(Sprite* sprite);
    
    void setGoalPosition(const Position& position);
    void setTime(float time);
    
    
    virtual void update(float dt);
    
    
private:
    Position _start;
    Position _goal;
    TimerAction* _pTimer;
};





/*
class LayerAction : public Action
{
PROTECT_CONSTRUCTOR_ACCESS:
    LayerAction();
    
public:
    virtual ~LayerAction();
    
    
private:
    Layer* _pTarget;
    
};


*/








#endif /* action_hpp */
