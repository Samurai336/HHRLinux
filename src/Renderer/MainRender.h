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

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <queue>
#include <vector>
#include <functional>

#include "../Define.h"

#include "FrameRateController.h"

struct RenderTextureInfo
{
    SDL_Texture* theTexture;
    SDL_Rect Src_R;
    SDL_Rect Dest_R;
    double Rotation;
    unsigned int RenderPriority;
};

struct RenderGeometryInfo
{
    int x1;
    int y1;
    int x2;
    int y2;
    float radious;
    SDL_Color RenderColor;
    unsigned int RenderPriority;
    bool isLine;
};


class RenderTextureInfoCompare
{
public:
    bool operator() (const RenderTextureInfo &A, const RenderTextureInfo &B) const;
};

class RenderGeometryInfoCompare
{
public:
    bool operator() (const RenderGeometryInfo &A, const RenderGeometryInfo &B) const;
};


class MainRender
{

	public:

        SDL_Texture* LoadTexture(const char* File);
		SDL_Texture* CreateTextureFromSurface(SDL_Surface*);


	public:

		MainRender(void);

		bool InitRenderer(SDL_Window*);

        bool Draw( SDL_Texture* theTexture, int X, int Y, double rotation = 0.0, float scale = 1.0, unsigned int RenderPriority = 15);
        bool Draw( SDL_Texture* theTexture, int X, int Y, int X2, int Y2, int W, int H, double rotation = 0.0, float scale = 1.0, unsigned int RenderPriority = 15);
        bool Draw( SDL_Texture* theTexture, int X, int Y, SDL_Rect &Src_Rect, double rotation = 0.0 , float scale = 1.0, unsigned int RenderPriority = 15);
        bool DrawLine(int x1, int y1, int x2, int y2, SDL_Color &RenderColor);
        bool DrawCircle(float X, float Y, float radious, SDL_Color &RenderColor);




		FrameRateController FrameRateControl;


		void CreateDisplayRect();

        void RenderDisplay();

		void Clean();
		//static SDL_Texture *OnLoad(char *filePath, SDL_Renderer *MainRenderer);


	private:        
        bool RenderLine(int x1, int y1, int x2, int y2, SDL_Color &RenderColor);
        bool RenderCircle(float X, float Y, float radious, SDL_Color &RenderColor);

        std::priority_queue <RenderGeometryInfo,std::vector<RenderGeometryInfo>, RenderGeometryInfoCompare> GemoetryRenderQueue;
        std::priority_queue <RenderTextureInfo,std::vector<RenderTextureInfo>, RenderTextureInfoCompare> TextureRenderQueue;
        SDL_Renderer*       Renderer;
};




