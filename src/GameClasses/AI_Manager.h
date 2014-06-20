#ifndef AI_MANAGER_H
#define AI_MANAGER_H

#include "AIUnits/HHREnemy.h"
#include <list>
#include <queue>


class AI_Manager
{
    public:
        AI_Manager();

    private:
        std::list<HHREnemy*> ActiveUnits;
        std::queue<HHREnemy*> NewUnits;
        HHR_Physics::Vector3 SpawnPoint;
        HHR_Physics::Vector3 ResetPoint;
        HHREnemy *UnitSample;
        bool isShooting;



};

#endif // AI_MANAGER_H
