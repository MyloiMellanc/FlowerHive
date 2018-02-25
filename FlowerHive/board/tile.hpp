//
//  tile.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 11..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef tile_hpp
#define tile_hpp

#include <vector>

#include "../core/vec2.h"
#include "../core/sprite.hpp"

class LineData;
class Line;


typedef int tile_owner;

enum TILE_OWNER
{
    NEUTRAL = 0
};


class TileData
{
public:
    
    
private:
    std::vector<LineData*> _pLine_list;
    
    int _tile_number;
    tile_owner _owner;
    
};






class Tile : public Sprite
{
public:
    Tile();
    
    virtual ~Tile();
    
    
    virtual void update(float dt);
    virtual void render(Renderer* renderer);
    virtual void touched(const Touch& touch);
    
private:
    std::vector<Line*> _pLine_list;
    
    TileData* _pData;
    
};



#endif /* tile_hpp */






