#include "orientedboundingbox2d.h"


namespace HHR_Physics
{

    OrientedBoundingBox2D::OrientedBoundingBox2D(const Vector3& center, const real w, const real h, real angle)
    {


    }

    void OrientedBoundingBox2D::SetUpBox(const Vector3& center, const real w, const real h, real angle)
    {
        Vector3 X( real_cos(DEGREES_TO_RADIANS(angle)), real_sin(DEGREES_TO_RADIANS(angle)), 1.0f);
        Vector3 Y(-real_sin(DEGREES_TO_RADIANS(angle)), real_cos(DEGREES_TO_RADIANS(angle)), 1.0f);
        width = w;
        height = h;
        Positon= center;

        X *= w/2;
        Y *= h/2;

        Vector3 Translation(w/2,h/2,0.0f);

        corner[0] = ((center) - X-Y)+Translation;
        corner[1] = ((center) + X-Y)+Translation;
        corner[2] = ((center) + X+Y)+Translation;
        corner[3] = ((center) - X+Y)+Translation;

        computeAxes();
    }

    void OrientedBoundingBox2D::moveTo(const Vector3 &center,real angle)
    {

        Vector3 X( real_cos(DEGREES_TO_RADIANS(angle)), real_sin(DEGREES_TO_RADIANS(angle)), 1.0f);
        Vector3 Y(-real_sin(DEGREES_TO_RADIANS(angle)), real_cos(DEGREES_TO_RADIANS(angle)), 1.0f);


        X *= width/2;
        Y *= height/2;

        Vector3 Translation(width/2,height/2,0.0f);

        corner[0] = ((center) - X-Y)+Translation;
        corner[1] = ((center) + X-Y)+Translation;
        corner[2] = ((center) + X+Y)+Translation;
        corner[3] = ((center) - X+Y)+Translation;

        Positon= center;

        computeAxes();
    }

    Vector3 OrientedBoundingBox2D::GetPositon() const
    {
        return Positon;
    }

    real OrientedBoundingBox2D::GetWidth() const
    {
        return width;
    }

    real OrientedBoundingBox2D::GetHeight() const
    {
        return height;
    }

    /*
    bool OrientedBoundingBox2D::overlaps(const OrientedBoundingBox2D &other) const
    {       
        return Collider::Check(*this, other); //overlaps1Way(other) && other.overlaps1Way(*this);  //
    }
    */

    void OrientedBoundingBox2D::computeAxes()
    {
        axis[0] = corner[1] - corner[0];
        axis[1] = corner[3] - corner[0];

        for (int a = 0; a < 2; ++a)
        {
            axis[a] /= axis[a].SquareMagnatude();
            origin[a] = corner[0].DotProduct(axis[a]);
        }
    }

    void OrientedBoundingBox2D::OnRender(MainRender &theRenderer, bool isColliding)
    {

#ifdef PHYSICS_DEBUG

        SDL_Color Player1Color;
        SDL_Color CollidingColor = {255,255,0,255};
        SDL_Color NotCollidingColor = {255,0,0,255};

        if(isColliding)
        {
            Player1Color = CollidingColor;
        }
        else
        {
            Player1Color = NotCollidingColor;
        }

        theRenderer.DrawLine((int)corner[0].x, (int)corner[0].y, (int)corner[1].x, (int)corner[1].y, Player1Color);
        theRenderer.DrawLine((int)corner[0].x, (int)corner[0].y, (int)corner[3].x, (int)corner[3].y, Player1Color);
        theRenderer.DrawLine((int)corner[1].x, (int)corner[1].y, (int)corner[2].x, (int)corner[2].y, Player1Color);
        theRenderer.DrawLine((int)corner[2].x, (int)corner[2].y, (int)corner[3].x, (int)corner[3].y, Player1Color);
#endif

    }




} 
