#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "Vector3.h"

namespace HHR_Physics
{
    class BoundingBox
    {

        public:
            Vector3 position;
            Vector3 extension;

        public:
            BoundingBox(Vector3 &Pos, Vector3 Ext):
            position(Pos), extension(Ext) {}


            ~BoundingBox();


        protected:
        private:
    };

}

#endif // BOUNDINGBOX_H
