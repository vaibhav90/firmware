/*
 * Copyright 2013 OpenMote Technologies, S.L.
 */

/**
 *
 * @file       adxl346.h
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2014
 * @brief
 * @ingroup
 *
 */

#ifndef ADXL346_H_
#define ADXL346_H_

#include "Sensor.h"

class I2c;

class Adxl346: public Sensor
{

public:
    Adxl346(I2c* i2c_);
    void enable(void);
    void reset(void);
    bool isPresent(void);
private:
    I2c * i2c;
};

#endif /* ADXL346_H_ */
