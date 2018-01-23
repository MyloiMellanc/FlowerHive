//
//  boardfactory.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 15..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef boardfactory_hpp
#define boardfactory_hpp

#include <stdio.h>

class BoardData;
class Board;

class BoardFactory
{
    BoardData* createBasicHexagonBoard(int length);
};


#endif /* boardfactory_hpp */
