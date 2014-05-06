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

#include "MainRender.h"




MainRender::MainRender(void)
{
	Renderer = NULL;
}



bool MainRender::InitRenderer(SDL_Window* windowToRenderTo)
{
	this->Renderer = SDL_CreateRenderer(windowToRenderTo, -1, SDL_RENDERER_ACCELERATED );

	if(this->Renderer == NULL)
	{

        printf("SDL Create failed: %s\n", SDL_GetError());


		return false;


	}
	else
    {
#ifdef DEBUG_MODE
        SDL_RendererInfo currentRenderInformation;
        SDL_GetRendererInfo(Renderer, &currentRenderInformation);

        printf("Render Information: name: %s, Flags: %u \n",currentRenderInformation.name, currentRenderInformation.flags );
#endif // DEBUG_MODE
    }


    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoothe
    SDL_RenderSetLogicalSize(Renderer,WWIDTH,WHEIGHT );
    SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);

	return true;
}

bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, double rotation, float scale, unsigned int RenderPriority )
{
	if(theTexture == NULL)
	{
		return false;
	}

    RenderTextureInfo itemForRender;

    itemForRender.theTexture = theTexture;
    itemForRender.Rotation = rotation;
    itemForRender.RenderPriority = RenderPriority;

    //SDL_Rect DestR;

    itemForRender.Dest_R.x = X ;
    itemForRender.Dest_R.y = Y;


	//should render at default size however will it then
	//tank preformance?
    SDL_QueryTexture(theTexture, NULL,NULL, &itemForRender.Dest_R.w, &itemForRender.Dest_R.h);

    itemForRender.Src_R.x = itemForRender.Src_R.y = 0;
    itemForRender.Src_R.h = itemForRender.Dest_R.h;
    itemForRender.Src_R.w = itemForRender.Dest_R.w;


    SDL_Rect offSetDiff;

    offSetDiff.x =  (itemForRender.Dest_R.w * scale) - itemForRender.Dest_R.w;
    offSetDiff.y =  (itemForRender.Dest_R.h * scale) - itemForRender.Dest_R.h;

    itemForRender.Dest_R.w *= scale;
    itemForRender.Dest_R.h *= scale;

    itemForRender.Dest_R.x -= (offSetDiff.x/2);
    itemForRender.Dest_R.y -= (offSetDiff.y/2);




    TextureRenderQueue.push(itemForRender);



   //itemForRender.Src_R;


    //SDL_RenderCopyEx(this->Renderer, theTexture, NULL, &DestR, rotation, NULL, SDL_FLIP_NONE);


	return true;

}

bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, int X2, int Y2, int W, int H, double rotation, float scale , unsigned int RenderPriority)
{
	if(theTexture == NULL)
	{
		return false;
	}

    RenderTextureInfo itemForRender;

    itemForRender.theTexture = theTexture;
    itemForRender.Rotation = rotation;
    itemForRender.RenderPriority = RenderPriority;


    //SDL_Rect DestR;

    itemForRender.Dest_R.w =  W * scale;
    itemForRender.Dest_R.h =  H * scale;
    itemForRender.Dest_R.x = X+((W * scale)/2);
    itemForRender.Dest_R.y = Y+((H * scale)/2);

    //SDL_Rect SrcR;

    itemForRender.Src_R.x = X2;
    itemForRender.Src_R.y = Y2;
    itemForRender.Src_R.w = W;
    itemForRender.Src_R.h = H;


    TextureRenderQueue.push(itemForRender);
    //SDL_RenderCopyEx(this->Renderer, theTexture, &SrcR, &DestR, rotation, NULL, SDL_FLIP_NONE);


	return true;

}

bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, SDL_Rect &Src_Rect, double rotation, float scale, unsigned int RenderPriority)
{

    if(theTexture == NULL)
	{
		return false;
	}

    RenderTextureInfo itemForRender;

    itemForRender.theTexture = theTexture;
    itemForRender.Rotation = rotation;
    itemForRender.RenderPriority = RenderPriority;

    itemForRender.Src_R = Src_Rect;

    int W,H;
    SDL_QueryTexture(theTexture, NULL,NULL, &W, &H);

    //SDL_Rect DestR;

    itemForRender.Dest_R.w = Src_Rect.w * scale;
    itemForRender.Dest_R.h = Src_Rect.h * scale;
    itemForRender.Dest_R.x = X+((Src_Rect.w * scale)/2);
    itemForRender.Dest_R.y = Y+((Src_Rect.h * scale)/2);

    TextureRenderQueue.push(itemForRender);



    //SDL_RenderCopyEx(this->Renderer, theTexture, &Src_Rect, &DestR, rotation, NULL, SDL_FLIP_NONE);

    return true;
}

bool MainRender::DrawLine(int x1, int y1, int x2, int y2, SDL_Color &RenderColor)
{    
    RenderGeometryInfo newLineGeo;
    newLineGeo.x1 = x1;
    newLineGeo.y1 = y1;
    newLineGeo.x2 = x2;
    newLineGeo.y2 = y2;
    newLineGeo.RenderPriority =  5;
    newLineGeo.RenderColor = RenderColor;
    newLineGeo.isLine = true;

    GemoetryRenderQueue.push(newLineGeo);

}

bool MainRender::DrawCircle(float X, float Y, float radious,SDL_Color &RenderColor)
{

    RenderGeometryInfo newLineGeo;
    newLineGeo.x1 = X;
    newLineGeo.y1 = Y;
    newLineGeo.radious= radious;
    newLineGeo.RenderPriority =  5;
    newLineGeo.RenderColor = RenderColor;
    newLineGeo.isLine = false;

    GemoetryRenderQueue.push(newLineGeo);
}



void MainRender::CreateDisplayRect()
{

	SDL_Rect DisplayRect;
	DisplayRect.x = 0;
	DisplayRect.y = 0;
	DisplayRect.w = WWIDTH;
	DisplayRect.h = WHEIGHT;

	//but not above here.

	SDL_RenderFillRect(Renderer, &DisplayRect);
}


void MainRender::RenderDisplay()
{

    RenderTextureInfo renderObject;
    while(!TextureRenderQueue.empty())
    {
        renderObject = TextureRenderQueue.top();

        SDL_RenderCopyEx(this->Renderer, renderObject.theTexture, &renderObject.Src_R, &renderObject.Dest_R, renderObject.Rotation, NULL, SDL_FLIP_NONE);

        TextureRenderQueue.pop();
    }

    RenderGeometryInfo renderGObject;
    while(!GemoetryRenderQueue.empty())
    {
        renderGObject = GemoetryRenderQueue.top();
        if(renderGObject.isLine)
        {
            RenderLine(renderGObject.x1,renderGObject.y1, renderGObject.x2, renderGObject.y2, renderGObject.RenderColor );
        }
        else
        {
            RenderCircle(renderGObject.x1,renderGObject.y1,renderGObject.radious,renderGObject.RenderColor);
        }
        GemoetryRenderQueue.pop();
    }
	//rendering can happen here
	SDL_RenderPresent(Renderer);
    SDL_RenderClear(Renderer);
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

	//or it can happen here

}

void MainRender::Clean()
{
    SDL_DestroyRenderer(this->Renderer);
}





bool MainRender::RenderLine(int x1, int y1, int x2, int y2, SDL_Color &RenderColor)
{
    SDL_SetRenderDrawColor(Renderer, RenderColor.r,RenderColor.g,RenderColor.b, RenderColor.a);

    SDL_RenderDrawLine(this->Renderer, x1, y1, x2, y2);

    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
}

bool MainRender::RenderCircle(float X, float Y, float radious, SDL_Color &RenderColor)
{
    SDL_SetRenderDrawColor(Renderer, RenderColor.r,RenderColor.g,RenderColor.b, RenderColor.a);

   float error = (float) - radious;
   float x = radious - 0.5f;
   float y = 0.5f;
   float cx = X - 0.5f;
   float cy = Y - 0.5f;

   while (x >= y)
   {
       SDL_RenderDrawPoint(Renderer,(int)(cx + x ), (int) (cy+y));
       SDL_RenderDrawPoint(Renderer,(int)(cx + y ), (int) (cy+x));

       if(x != 0)
       {
           SDL_RenderDrawPoint(Renderer,(int)(cx - x ), (int) (cy+y));
           SDL_RenderDrawPoint(Renderer,(int)(cx + y ), (int) (cy-x));
       }

       if(y != 0)
       {
           SDL_RenderDrawPoint(Renderer,(int)(cx + x ), (int) (cy-y));
           SDL_RenderDrawPoint(Renderer,(int)(cx - y ), (int) (cy+x));
       }

       if (x != 0 && y != 0)
       {
           SDL_RenderDrawPoint(Renderer,(int)(cx - x ), (int) (cy-y));
           SDL_RenderDrawPoint(Renderer,(int)(cx - y ), (int) (cy-x));
       }

       error += y;
       y++;
       error += y;

       if(error >= 0)
       {
           --x;
           error -= x;
           error -= x;
       }
   }

   SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
}


SDL_Texture* MainRender::LoadTexture(const char* File)
{
	return IMG_LoadTexture(Renderer, File);
}

SDL_Texture* MainRender::CreateTextureFromSurface(SDL_Surface* surface)
{
    return SDL_CreateTextureFromSurface(Renderer,surface);

}

bool RenderTextureInfoCompare::operator()(const RenderTextureInfo &A, const RenderTextureInfo &B) const
{
    return (A.RenderPriority>B.RenderPriority);
}


bool RenderGeometryInfoCompare::operator()(const RenderGeometryInfo &A, const RenderGeometryInfo &B) const
{
    return (A.RenderPriority<B.RenderPriority);
}
