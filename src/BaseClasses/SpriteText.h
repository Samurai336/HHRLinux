#ifndef SPRITETEXT_H
#define SPRITETEXT_H


#include <SDL2/SDL_ttf.h>
#include <string>
#include "../Renderer/MainRender.h"


class SpriteText
{
    public:
        SpriteText();
        SpriteText(char* fontTTFFile, char* StartText = "", unsigned int fontSize = 12, int positionX = 0, int positionY =0, SDL_Color Color = {255, 255, 255 });
        bool LoadSpriteText(char* fontTTFFile, char* StartText = "", unsigned int fontSize = 12, int positionX = 0, int positionY =0,  SDL_Color Color = {255, 255, 255 });
        virtual void UpDateText(char* newText);
        virtual void OnRender(MainRender &theRenderer);

        virtual ~SpriteText();
    protected:
        void UpdateSpriteTexture(MainRender &theRenderer);
        bool needsUpdate;
        SDL_Texture* textSprite;
        TTF_Font*    fontFile;
        SDL_Rect    TextDisplayRect;
        SDL_Color   TextColor;
        unsigned int textFontSize;
        std::string  theText;


    private:
};

#endif // SPRITETEXT_H
