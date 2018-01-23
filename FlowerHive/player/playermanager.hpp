//
//  playermanager.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef playermanager_hpp
#define playermanager_hpp

#include <vector>

class PlayerData;
class Player;

class PlayerManagerData
{
    
private:
    std::vector<PlayerData*> _pPlayer_list;
};



class PlayerManager
{
    
private:
    std::vector<Player*> _pPlayer_list;
};

#endif /* playermanager_hpp */
