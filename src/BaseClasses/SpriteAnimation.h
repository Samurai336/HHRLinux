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
