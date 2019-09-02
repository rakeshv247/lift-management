#include "tower.h"
#include "config.h"
#include "logger.h"
#include <inttypes.h>

TowerManager* TowerManager::_self = nullptr;

bool TowerManager::InitTowerManager()
{
  if ( !_self ) {
    _self = new TowerManager();
    if ( !_self ) {
      return false;
    }
  }

  return true;
}

void TowerManager::DestroyTowerManager()
{
  if ( _self ) {
    delete _self;
  }
}

const ITower& TowerManager::GetTowerInstance(uint32_t towerId)
{
  return *(_self->_instances[--towerId]);
}

bool TowerManager::InitTowerInstances(uint32_t totalInstances)
{
  _self->_instances.clear();
  for ( uint32_t i = 0; i < totalInstances; i++ ) {
    ITower* instance = new Tower(i, 15);
    if ( !instance ) {
      Logger::write(ERROR, "Error creating tower instance instance %" PRIu32 "\n", i+1);
      return false;
    }
    _self->_instances[i] = instance;
  }

  return true;
}
