#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <stdint.h>
#include <vector>

class IFloor {
public:
  virtual uint16_t GetFloorNo() = 0;
  virtual bool IsFunctional() = 0;
};

class INonFunctionalFloor : public IFloor {
public:
  virtual uint32_t GetTotalNonFunctionalDays() = 0;
};

class NonFunctionalFloor : public INonFunctionalFloor {
public:
  NonFunctionalFloor(uint16_t floorNo, uint32_t total) : _floorNo(floorNo),
	                                                 _isFunctional(false),
	                                                 _totalNonFunctionalDays(total) {}
  ~NonFunctionalFloor() {}
  uint16_t GetFloorNo() { return _floorNo; }
  bool IsFunctional() { return _isFunctional; }
  uint32_t GetTotalNonFunctionalDays() { return _totalNonFunctionalDays; }

private:
  uint16_t _floorNo;
  bool _isFunctional;
  uint32_t _totalNonFunctionalDays;
};

class IFunctionalFloor : public IFloor {
public:
  virtual uint32_t GetTotalFunctionalDays() = 0;
};	

class FunctionalFloor : public IFunctionalFloor {
public:
  FunctionalFloor(uint16_t floorNo, uint32_t total) : _floorNo(floorNo),
	                                              _isFunctional(true),
	                                              _totalFunctionalDays(total) {}
  ~FunctionalFloor() {}
  uint16_t GetFloorNo() { return _floorNo; }
  bool IsFunctional() { return _isFunctional; }
  uint32_t GetTotalFunctionalDays() { return _totalFunctionalDays; }

private:
  uint16_t _floorNo;
  bool _isFunctional;
  uint32_t _totalFunctionalDays;
};

class FloorManager {
public:
  static bool Init();
  static void Destroy();
  static IFloor& GetFloorInstance(uint16_t floorNo);
  static bool InitFloorInstances(uint16_t totalFloors);

private:
  static FloorManager* _self;
  std::vector<IFloor*> _instances;
private:
  IFloor& _getFloorInstance(uint16_t floorNo);
  bool _initFloorInstances(uint16_t totalFloors);
};

#endif
