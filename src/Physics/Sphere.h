#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3.h"

namespace HHR_Physics
{
    class Sphere
    {
        public:
            Vector3 position;
            real radious;

        public:
            Sphere(Vector3 &pos, real rad):
                position(pos), radious(rad){}

            ~Sphere();
        protected:
        private:
    };
}
#endif // SPHERE_H
