//
//  action.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "action.hpp"
#include "sprite.hpp"

Action::Action()
: _running(false)
, _finished(false)
{ }


Action::~Action()
{
    
}

bool Action::isRunning() const
{
    return _running;
}

bool Action::isFinished() const
{
    return _finished;
}

void Action::run()
{
    _running = true;
}


void Action::finish()
{
    _running = false;
    _finished = true;
}



TimerAction::TimerAction(float time)
: Action()
, _current(0.0)
, _goal(time)
{ }


TimerAction::~TimerAction()
{
    
}

void TimerAction::setGoal(float goal)
{
    _goal = goal;
}

float TimerAction::getGoalTime() const
{
    return _goal;
}

float TimerAction::getCurrentTime() const
{
    return _current;
}

float TimerAction::getGoalPercentage() const
{
    float percent = _current / _goal;
    if(percent >= 1.0)
        return 1.0;
    else
        return percent;
}

void TimerAction::update(float dt)
{
    if (isRunning())
    {
        _current += dt;
        if (_current >= _goal)
            finish();
    }
}


SpriteAction::SpriteAction()
: Action()
, _pTarget(nullptr)
{ }

SpriteAction::SpriteAction(Sprite* sprite)
: Action()
, _pTarget(sprite)
{ }


SpriteAction::~SpriteAction()
{
    
}

Sprite* SpriteAction::getTargetSprite()
{
    return _pTarget;
}


MoveTo::MoveTo(Position position, float time)
: SpriteAction()
, _goal(position)
{
    _pTimer = new TimerAction(time);
}

MoveTo::MoveTo(Sprite* sprite, Position position, float time)
: SpriteAction(sprite)
, _goal(position)
{
    _pTimer = new TimerAction(time);
    setSprite(sprite);
}


MoveTo::~MoveTo()
{
    delete _pTimer;
}

void MoveTo::setSprite(Sprite* sprite)
{
    _pTarget = sprite;
    _start = _pTarget->getPosition();
}

void MoveTo::setGoalPosition(const Position& position)
{
    _goal = position;
}

void MoveTo::setTime(float time)
{
    _pTimer->setGoal(time);
}

void MoveTo::update(float dt)
{
    if (_pTimer->isRunning() == false)
        _pTimer->run();
    
    if (isRunning())
    {
        _pTimer->update(dt);
        float percentage = _pTimer->getGoalPercentage();
        
        Position current = _start + ((_goal - _start) * percentage);
        _pTarget->setPosition(current);
        
        if(_pTimer->isFinished())
            finish();
    }
}






