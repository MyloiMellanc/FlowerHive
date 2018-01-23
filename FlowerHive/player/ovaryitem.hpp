//
//  ovaryitem.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef ovaryitem_hpp
#define ovaryitem_hpp

#include "item.hpp"


class OvaryItemData : public ItemData
{
    //추가적으로 소비되는 자원이 없으며, 다 쓸시 인벤토리에서 사라집니다. (갯수제한이 있습니다.)
};


class OvaryItem : public Item
{
    
private:
    OvaryItemData* _pData;
    
};

#endif /* ovaryitem_hpp */
