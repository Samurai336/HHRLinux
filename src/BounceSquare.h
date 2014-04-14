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
#include "Define.h"
#include "BaseClasses/BaseUnit.h"
#include "Physics/Vector3.h"
#include "Physics/orientedboundingbox2d.h"





class BounceSquare :
	public BaseUnit
{
	public:
		BounceSquare(void);

		bool Load(char* File);

		void OnLoop();

        HHR_Physics::BoundingBox GetCollisionObject();

		void OnRender(MainRender	&theRenderer);

		void OnCleanup();

		void setSpeed(float xSpeed =0, float ySpeed=0);

		~BounceSquare(void);

    protected:
        virtual void UpdateCollisionObj();


	private:
        float speedX, speedY;
        HHR_Physics::BoundingBox BBCollisionObject;





};

