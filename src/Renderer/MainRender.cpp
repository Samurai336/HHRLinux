#include "MainRender.h"


MainRender::MainRender(void)
{
	Renderer = NULL;
}



bool MainRender::InitRenderer(SDL_Window* windowToRenderTo)
{
	this->Renderer = SDL_CreateRenderer(windowToRenderTo, -1, SDL_RENDERER_TARGETTEXTURE|SDL_RENDERER_PRESENTVSYNC );

	if(this->Renderer == NULL)
	{
		return false;
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





