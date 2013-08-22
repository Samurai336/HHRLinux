/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/


#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#pragma once

#include "BaseUnit.h"

class SpriteAnimation: public BaseUnit
{
    public:
        SpriteAnimation(void);
        SpriteAnimation(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop);
        bool CreateAnimatedSprite(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop);
        void SetLoop(bool);
        void SetNumberRow(unsigned int);
        void SetNumberColumn(unsigned int);
        void SetRate(Uint32);
        void OnLoop();
		void OnRender(MainRender	&theRenderer);
		void OnCleanup();
		void  SetPosition(float MoveX, float MoveY);


        virtual ~SpriteAnimation();

    protected:

    private:
        void CalculateSpriteSize();
        unsigned int numberOfColumns;
        unsigned int numberOfRows;
        uint32_t LastUpDate;
        uint32_t Rate;
        unsigned int currrentRow;
        unsigned int currentColumn;
        bool loop;
        SDL_Rect Sprite_Rect;



};

#endif // SPRITEANIMATION_H