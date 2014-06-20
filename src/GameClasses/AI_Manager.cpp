#include "AI_Manager.h"

template <class T>
AI_Manager<T>::AI_Manager()
{
}

template <class T>
void AI_Manager<T>::SetUpAI(HHR_Physics::Vector3 SetSpawnPoint, HHR_Physics::Vector3 setResetPoint, uint32_t setSpawnRate, T* SetUnitModel)
{
    SpawnPoint = SetSpawnPoint;
    ResetPoint = setResetPoint;
    SpawnRestTime = setSpawnRate;
    UnitModel = SetUnitModel;
}

template <class T>
void AI_Manager<T>::OnLoop()
{
    uint32_t ticks = SDL_GetTicks();

    typename std::list<T*>::iterator activeUnitsItor = ActiveUnits.begin();

    for(; activeUnitsItor != ActiveUnits.end(); ++activeUnitsItor )
    {
        (*activeUnitsItor)->OnLoop();

        if((*activeUnitsItor)->GetPosition().y > ResetPoint.y)
        {
            NewUnits.push((*activeUnitsItor));

            activeUnitsItor--;
            ActiveUnits.remove((*(activeUnitsItor+1)));
        }
    }

    if(SpawnCool < ticks)
    {
        SpawnNewUnit();
        SpawnCool = SDL_GetTicks() + SpawnRestTime;
    }

}

template <class T>
void AI_Manager<T>::SpawnNewUnit()
{
    T* newActiveUnit;
    if(NewUnits.empty() != true)
    {
        newActiveUnit = NewUnits.front();
        NewUnits.pop();
    }
    else
    {
        newActiveUnit = new T(UnitModel);

    }

    newActiveUnit->Reset();
    newActiveUnit->SetPosition(SpawnPoint);


}
