//
//  line.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 11..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef line_hpp
#define line_hpp

#include "../core/vec2.h"
#include "../core/sprite.hpp"


class TileData;
class Tile;

class LineData
{
public:
    
    
    
private:
    TileData* _pAdjust_tile[2];
    
};



class Line : public Sprite
{
public:
    
    
private:
    Tile* _pAdjust_tile[2];
    
    LineData* _pData;
    
};

#endif /* line_hpp */





