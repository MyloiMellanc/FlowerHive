//
//  layer.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef layer_hpp
#define layer_hpp


#include "macro.h"

#include <vector>

class Sprite;
//class LayerAction;


class LayerMethod
{
public:
    
};

class LayerMethodSDL : public LayerMethod
{
    
    
    //background
    
};

class Layer
{
    
    
    
private:
    
    std::vector<Layer*>  _pSublayer_list;
    std::vector<Sprite*> _pSprite_list;
    
    //std::vector<LayerAction*> _pAction_list;
    
    LayerMethod* _pMethod;
};



#endif /* layer_hpp */
