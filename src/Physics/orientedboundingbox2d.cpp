#include "orientedboundingbox2d.h"


namespace HHR_Physics
{

    OrientedBoundingBox2D::OrientedBoundingBox2D(const Vector3& center, const real w, const real h, real angle)
    {
        Vector3 X( real_cos(angle), real_sin(angle), 1.0f);
        Vector3 Y(-real_sin(angle), real_cos(angle), 1.0f);


        X *= w/2;
        Y *= h/2;



        corner[0] = center-(X-Y);
        corner[1] = center +  (X-Y) ;
        corner[2] = center +  (X+Y);
        corner[3] = center-(X+Y);

        computeAxes();
    }

    void OrientedBoundingBox2D::moveTo(const Vector3 &center)
    {
        Vector3 centroid = (corner[0]+corner[1]+corner[2]+corner[3])/4;

        Vector3 translation = center = centroid;

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
            axis[a] /= axis[a].Magnatude();
            origin[a] = corner[0].DotProduct(axis[a]);
        }
    }


} 
