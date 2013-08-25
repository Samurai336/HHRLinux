#include "SpriteText.h"

SpriteText::SpriteText():theText(""), textSprite(NULL), fontFile(NULL)
{
    TextColor = {255,255,255};

    TextDisplayRect.x = TextDisplayRect.y = TextDisplayRect.h = TextDisplayRect.w  = 0;

    needsUpdate = false;


    //ctor
}

SpriteText::SpriteText(char* fontTTFFile, char* StartText, unsigned int fontSize, int positionX , int positionY, SDL_Color Color)
{
    LoadSpriteText(fontTTFFile, StartText, fontSize, positionX, positionY, Color);


}

bool SpriteText::LoadSpriteText(char* fontTTFFile, char* StartText, unsigned int fontSize, int positionX, int positionY, SDL_Color Color)
{
    if((fontFile = TTF_OpenFont( fontTTFFile, fontSize ))==NULL)
    {
        return false;
    }

    theText = StartText;
    textFontSize = fontSize;
    TextDisplayRect.x = positionX;
    TextDisplayRect.y = positionY;
    TextColor = Color;

    needsUpdate = true;

    return true;
}

void SpriteText::UpDateText(char* newText)
{
    theText = newText;


}
void SpriteText::UpdateSpriteTexture(MainRender &theRenderer)
{
    SDL_Surface *surfSpriteText = TTF_RenderText_Solid(fontFile, theText.c_str(), TextColor);
    SDL_DestroyTexture(textSprite);
    textSprite = theRenderer.CreateTextureFromSurface(surfSpriteText );
    needsUpdate = true;
}


void SpriteText::OnRender(MainRender &theRenderer)
{
    if(needsUpdate == true)
    {
        UpdateSpriteTexture(theRenderer);
        needsUpdate = false;
    }

    theRenderer.Draw(textSprite, TextDisplayRect.x, TextDisplayRect.y);

}

SpriteText::~SpriteText()
{
    //dtor
}
