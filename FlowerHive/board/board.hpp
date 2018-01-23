//
//  board.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 11..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include "../core/vec2.h"
#include "../core/sprite.hpp"
#include <vector>


class TileData;
class LineData;
class Tile;
class Line;


class BoardData
{
    
private:
    std::vector<TileData*> _pTile_list;
    std::vector<LineData*> _pLine_list;
};



class Board : public Sprite
{
public:
    
    
    void setBoardData(BoardData* data);
    void addTile(Tile* tile);
    void addLine(Line* line);
    
    
    
    void setCenterPosition(const fvec2& center_position);
    void setInterval(const float interval);
    
    
    fvec2 getCenterPosition() const;
    float getInterval() const;
    
private:
    BoardData* _pData;
    
    std::vector<Tile*> _pTile_list;
    std::vector<Line*> _pLine_list;
    
    fvec2 _center_position;
    float _interval;
};


#endif /* board_hpp */







