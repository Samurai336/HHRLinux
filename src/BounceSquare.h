#pragma once
#include "BaseClasses\BaseUnit.h"
#include "Define.h"


class BounceSquare :
	public BaseUnit
{
	public:
		BounceSquare(void);

		void Load(char* File); 

		void OnLoop();
		
		void OnRender(); 

		void OnCleanup();

		void setSpeed(float xSpeed =0, float ySpeed=0); 

		~BounceSquare(void);
	private: 
		float speedX, speedY;
		int width, height; 


};

