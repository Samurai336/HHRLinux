#include "orientedboundingbox2d.h"


namespace HHR_Physics
{

    OrientedBoundingBox2D::OrientedBoundingBox2D(const Vector3& center, const real w, const real h, real angle)
    {


        SetUpBox(center,w,h,angle );


        /*
        Vector3 X( real_cos(angle), real_sin(angle), 1.0f);
        Vector3 Y(-real_sin(angle), real_cos(angle), 1.0f);


        X *= w/2;
        Y *= h/2;



        corner[0] = center-(X-Y);
        corner[1] = center +  (X-Y) ;
        corner[2] = center +  (X+Y);
        corner[3] = center-(X+Y);

        computeAxes();
        */
    }

    void OrientedBoundingBox2D::SetUpBox(const Vector3& center, const real w, const real h, real angle)
    {
        Vector3 X( real_cos(angle), real_sin(angle), 1.0f);
        Vector3 Y(-real_sin(angle), real_cos(angle), 1.0f);
        width = w;
        height = h;

        X *= w/2;
        Y *= h/2;

        Vector3 Translation(w/2,h/2,0.0f);

        corner[0] = ((center) - X-Y)+Translation;
        corner[1] = ((center) + X-Y)+Translation;
        corner[2] = ((center) + X+Y)+Translation;
        corner[3] = ((center) - X+Y)+Translation;

        computeAxes();
    }

    void OrientedBoundingBox2D::moveTo(const Vector3 &center)
    {
        Vector3 centroid;
        centroid.x = (corner[0].x+corner[1].x+ corner[2].x+corner[3].x)/4;
        centroid.y = (corner[0].y+corner[1].y +corner[2].y+corner[3].y)/4;

        Vector3 AdjustedCenter(center.x + width/2, center.y + height/2, center.z);

        Vector3 translation =   AdjustedCenter - centroid;

        for(int c = 0; c<4; ++c)
        {
            corner[c] += translation;
        }

        computeAxes();
    }

    bool OrientedBoundingBox2D::overlaps(const OrientedBoundingBox2D &other) const
    {
        return overlaps1Way(other) && other.overlaps1Way(*this);
    }


    bool OrientedBoundingBox2D::overlaps1Way(const OrientedBoundingBox2D &other) const
    {
        for(int a = 0; a<2; ++a)
        {
            real t = other.corner[a].DotProduct(axis[a]);

            real tMin = t;
            real tMax = t;

            for (int c = 1; c <4; ++c)
            {
                t = other.corner[c].DotProduct(axis[a]);

                if (t< tMin)
                {
                    tMin = t;
                }
                else if(t> tMax)
                {
                    tMax = t;
                }

            }

            if((tMin > 1 + origin[a]) ||(tMax< origin[a]))
            {
                return false;
            }
        }

        return true;
    }

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

    void OrientedBoundingBox2D::OnRender(MainRender &theRenderer)
    {

#ifdef PHYSICS_DEBUG
        SDL_Color Player1Color = {255,0,0,255};
        theRenderer.DrawLine((int)corner[0].x, (int)corner[0].y, (int)corner[1].x, (int)corner[1].y, Player1Color);
        theRenderer.DrawLine((int)corner[0].x, (int)corner[0].y, (int)corner[3].x, (int)corner[3].y, Player1Color);
        theRenderer.DrawLine((int)corner[1].x, (int)corner[1].y, (int)corner[2].x, (int)corner[2].y, Player1Color);
        theRenderer.DrawLine((int)corner[2].x, (int)corner[2].y, (int)corner[3].x, (int)corner[3].y, Player1Color);


#endif

    }




} 
