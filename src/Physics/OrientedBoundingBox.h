#ifndef ORIENTEDBOUNDINGBOX_H
#define ORIENTEDBOUNDINGBOX_H

#include "BoundingBox.h"


namespace HHR_Physics
{
    class OrientedBoundingBox : public BoundingBox
    {
        public:

            Vector3 Orientation;


        public:
            OrientedBoundingBox(){}
            OrientedBoundingBox(Vector3 &Pos, Vector3 &Ext, Vector3 &Orent):
            BoundingBox(Pos,Ext), Orientation(Orent) {}
            Vector3 GetXAxis();
            Vector3 GetYAxis();
            Vector3 GetZAxis();

            ~OrientedBoundingBox(){}
        protected:
        private:
    };
}
#endif // ORIENTEDBOUNDINGBOX_H
