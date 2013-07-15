#ifndef BASEUNIT_H
#define BASEUNIT_H





#include <SDL2/SDL.h> 





class BaseUnit 
{
		public:
			BaseUnit(void);
			
			virtual void Load(char* File);

			virtual void OnLoop();

			virtual void OnRender(); 

			virtual void OnCleanup();

			void  SetPosition(float MoveX, float MoveY);

			void setRenderOrder(int newRenderOrder) { renderOrder = newRenderOrder; };
			
			~BaseUnit(void);

		protected:
			
			SDL_Texture* unitTexture; 
			
			float X,Y; 
			
			double rotation; 

			int renderOrder; 
			
			


			



};

#endif 