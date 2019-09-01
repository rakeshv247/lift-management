#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <stdint.h>

class ITower {
public:
  virtual uint32_t GetTowerId() = 0;
};

class Tower : public ITower {
public:
  Tower(uint32_t towerId) : _towerId(towerId) {}
  ~Tower() {}
  uint32_t GetTowerId() { return _towerId; }
private:
  uint32_t _towerId;
};

#endif
