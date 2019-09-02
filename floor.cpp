#include "floor.h"
#include "logger.h"
#include <inttypes.h>

FloorManager* FloorManager::_self = nullptr;

bool FloorManager::Init()
{
  if ( !_self ) {
    _self = new FloorManager();
    if ( !_self ) {
      Logger::write(ERROR, "Error creating FloorManager instance \n");
      return false;
    }
  }

  return true;
}

void FloorManager::Destroy()
{
  if ( _self ) {
    delete _self;
  }
}

IFloor& FloorManager::GetFloorInstance(uint16_t floorNo)
{
  return _self->_getFloorInstance(floorNo);
}

IFloor& FloorManager::_getFloorInstance(uint16_t floorNo)
{
  return *(_instances[--floorNo]);
}

bool FloorManager::InitFloorInstances(uint16_t totalFloors)
{
  return _self->_initFloorInstances(totalFloors);
}

bool FloorManager::_initFloorInstances(uint16_t totalFloors)
{
  _instances.clear();
  for ( uint32_t i = 0; i < totalFloors; i++ ) {
  }

  return true;
}
