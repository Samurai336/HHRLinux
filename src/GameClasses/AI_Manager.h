#ifndef AI_MANAGER_H
#define AI_MANAGER_H

#include "AIUnits/HHREnemy.h"
#include <list>
#include <queue>

template <class T>
class AI_Manager
{
    public:
        AI_Manager();
        void SetUpAI(HHR_Physics::Vector3 SetSpawnPoint, HHR_Physics::Vector3 setResetPoint, uint32_t setSpawnRate, T* SetUnitModel);
        void OnLoop();


    private:
        void SpawnNewUnit();
        std::list<T*> ActiveUnits;
        std::queue<T*> NewUnits;
        HHR_Physics::Vector3 SpawnPoint;
        HHR_Physics::Vector3 ResetPoint;
        uint32_t SpawnRestTime, SpawnCool;
        T* UnitModel;

        bool isShooting;



};

#endif // AI_MANAGER_H
