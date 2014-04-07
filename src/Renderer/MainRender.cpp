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



	return true;
}

bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, double rotation)
{
	if(theTexture == NULL)
	{
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;


	//should render at default size however will it then
	//tank preformance?
	SDL_QueryTexture(theTexture, NULL,NULL, &DestR.w, &DestR.h);


	SDL_RenderCopyEx(this->Renderer, theTexture, NULL, &DestR, rotation, NULL, SDL_FLIP_NONE);


	return true;

}

bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, int X2, int Y2, int W, int H, double rotation)
{
	if(theTexture == NULL)
	{
		return false;
	}


	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = W;
	DestR.h = H;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_RenderCopyEx(this->Renderer, theTexture, &SrcR, &DestR, rotation, NULL, SDL_FLIP_NONE);


	return true;

}

bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, SDL_Rect &Src_Rect, double rotation)
{

    if(theTexture == NULL)
	{
		return false;
	}


	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = Src_Rect.w;
	DestR.h = Src_Rect.h;


    SDL_RenderCopyEx(this->Renderer, theTexture, &Src_Rect, &DestR, rotation, NULL, SDL_FLIP_NONE);

    return true;
}

bool MainRender::DrawLine(int x1, int y1, int x2, int y2, SDL_Color &RenderColor)
{
    SDL_SetRenderDrawColor(Renderer, RenderColor.r,RenderColor.g,RenderColor.b, RenderColor.a);

    SDL_RenderDrawLine(this->Renderer, x1, y1, x2, y2);

    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

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


SDL_Texture* MainRender::LoadTexture(char* File)
{
	return IMG_LoadTexture(Renderer, File);
}

SDL_Texture* MainRender::CreateTextureFromSurface(SDL_Surface* surface)
{
    return SDL_CreateTextureFromSurface(Renderer,surface);

}





