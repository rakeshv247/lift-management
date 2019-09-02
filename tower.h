#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <stdint.h>
#include <vector>

class ITower {
public:
  virtual uint32_t GetTowerId() = 0;
  virtual uint16_t GetTotalFloors() = 0;
};

class Tower : public ITower {
public:
  Tower(uint32_t towerId, uint16_t totalFloors) : _towerId(towerId),
                                                  _totalFloors(totalFloors) {}
  ~Tower() {}
  uint32_t GetTowerId() { return _towerId; }
  uint16_t GetTotalFloors() { return _totalFloors; }
private:
  uint32_t _towerId;
  uint16_t _totalFloors;
};

class TowerManager {
public:
  static bool InitTowerManager();
  static void DestroyTowerManager();
  static const ITower& GetTowerInstance(uint32_t towerId);
  static bool InitTowerInstances(uint32_t totalInstances);

private:
  static TowerManager* _self;
  std::vector<ITower*> _instances;
};

#endif
