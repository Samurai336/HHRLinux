#include "OrientedBoundingBox.h"



namespace HHR_Physics
{
    OrientedBoundingBox::~OrientedBoundingBox()
    {
        //dtor
    }



    Vector3 OrientedBoundingBox::GetXAxis()
    {

        real cosineTheta = real_cos(Orientation.x);
        real sineTheta   = real_sin(Orientation.x);

        return Vector3(this->position.x,
                      (this->position.y * cosineTheta)+(this->position.z * (-1 *sineTheta)),
                      (this->position.y * sineTheta)+(this->position.z * cosineTheta));

    }
    Vector3 OrientedBoundingBox::GetYAxis()
    {

        real cosineTheta = real_cos(Orientation.y);
        real sineTheta   = real_sin(Orientation.y);

        return Vector3((this->position.x*cosineTheta) + (this->position.z * sineTheta),
                       this->position.y,
                       (this->position.x (-1*sineTheta) + (this->position.z * cosineTheta));

    }
    Vector3 OrientedBoundingBox::GetZAxis()
    {

        real cosineTheta = real_cos(Orientation.z);
        real sineTheta   = real_sin(Orientation.z);

        return Vector3((this->position.x * cosineTheta) + (this->position.y (-1*sineTheta)),
                       (this->position.x * sineTheta) + (this->position.y*cosineTheta),
                        this->position.z)

    }

}
