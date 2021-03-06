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

#ifndef BASEUNIT_H
#define BASEUNIT_H





#include <SDL2/SDL.h>
#include "../Renderer/MainRender.h"
#include "../Physics/Vector3.h"
#include "../Physics/CollisionObjects.h"

class MainRender;





class BaseUnit
{
		public:
			BaseUnit(void);

			virtual bool Load(char* File);

            virtual void OnLoop();

			virtual void OnRender(MainRender &theRenderer);

			virtual void OnCleanup();

            virtual HHR_Physics::CollisionObject* GetCollisionObject() const {return NULL;}

            void  SetPosition(const float MoveX, const float MoveY);

            void  SetPosition(const HHR_Physics::Vector3 &newPosition);

            void  SetScale(const float newScale);

            float GetScale();

            void setRenderOrder(int newRenderOrder) { renderOrder = newRenderOrder; }

			int GetWidth(){return width;}

			int GetHeight(){return height;}

            HHR_Physics::Vector3 GetPosition();

			~BaseUnit(void);

        protected:

            virtual void UpdateCollisionObj(){}

			SDL_Texture* unitTexture;

            //float X,Y;

            HHR_Physics::Vector3 Position;

			int width, height;

			double rotation;

            float Scale;

			int renderOrder;








};

#endif
