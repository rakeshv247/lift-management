#ifndef LIFT_H
#define LIFT_H

#include <iostream>
#include <stdint.h>

class ILift {
public:
  virtual uint16_t GetLiftId() = 0;
  virtual uint16_t GetCapacityInKg() = 0;
  virtual bool IsFunctional() = 0;
};

class INonFunctionalLift : public ILift {
public:
  virtual uint32_t GetLastNonFunctionalDays() = 0;
};

class NonFunctionalLift : public INonFunctionalLift {
public:
  NonFunctionalLift(uint16_t liftId,
		    uint16_t capacity,
		    uint32_t lastNonFunctionalDays,
		    bool isFunctional = false) : _liftId(liftId),
	                                         _capacity(capacity),
	                                         _lastNonFunctionalDays(lastNonFunctionalDays),
	                                         _isFunctional(isFunctional) {}
  ~NonFunctionalLift() {}
  uint32_t GetLastNonFunctionalDays() { return _lastNonFunctionalDays; }
private:
  uint16_t _liftId;
  uint16_t _capacity;
  uint32_t _lastNonFunctionalDays;
  bool _isFunctional;
};

class IFunctionalLift : public ILift {
public:
  virtual uint32_t GetLastFunctionalDays() = 0;
};

class FunctionalLift : public IFunctionalLift {
public:
  FunctionalLift(uint16_t liftId,
                 uint16_t capacity,
                 uint32_t lastFunctionalDays,
                 bool isFunctional = false) : _liftId(liftId),
                                              _capacity(capacity),
                                              _lastFunctionalDays(lastFunctionalDays),
	                                      _isFunctional(isFunctional) {}
  ~FunctionalLift() {}
  uint32_t GetLastFunctionalDays() { return _lastFunctionalDays; }
private:
  uint16_t _liftId;
  uint16_t _capacity;
  uint32_t _lastFunctionalDays;
  bool _isFunctional;
};

class IServiceLift : public ILift {
public:
  virtual uint8_t GetServiceLiftUsableHours() = 0;
};

class ServiceLift : public IServiceLift {
public:
  ServiceLift(uint16_t liftId,
              uint16_t capacity,
              uint8_t usableHours,
	      bool isFunctional = false) : _liftId(liftId),
                                           _capacity(capacity),
	                                   _usableHours(usableHours),
                                           _isFunctional(isFunctional) {}
  ~ServiceLift() {}
  uint8_t GetServiceLiftUsableHours() { return _usableHours; }
private:
  uint16_t _liftId;
  uint16_t _capacity;
  uint8_t _usableHours;
  bool _isFunctional;
};

#endif
