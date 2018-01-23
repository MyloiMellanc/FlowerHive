//
//  tile.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 11..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef tile_hpp
#define tile_hpp

#include "../core/vec2.h"
#include "../core/sprite.hpp"

class LineData;



class TileData
{
public:
    virtual TileData* getAdjustTileData(int direction);
    
private:
    //TileData* _pAdjust_tile[6];
    
    int _tile_number;
    int _owner;
    
};

class HexTileData : public TileData
{
public:
    virtual TileData* getAdjustTileData(int direction);
    
private:
    TileData*   _pAdjust_tile[6];
};








class Tile : public Sprite
{
public:
    virtual Tile* getAdjustTile(int direction);
    
    
private:
    //Tile* _pAdjust_tile[6];
    
    TileData* _pData;
    
};


class HexTile : public Tile
{
public:
    virtual Tile* getAdjustTile(int direction);
    
private:
    Tile* _pAdjust_tile[6];
};


#endif /* tile_hpp */






