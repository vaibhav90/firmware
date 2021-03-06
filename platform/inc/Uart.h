/*
 * Copyright 2013 OpenMote Technologies, S.L.
 */

/**
 *
 * @file       Uart.h
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2014
 * @brief
 * @ingroup
 *
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#include "Gpio.h"
#include "Callback.h"

class Gpio;

class Uart
{

friend class InterruptHandler;

public:
    Uart(uint32_t peripheral, uint32_t base, uint32_t clock, uint32_t interrupt, GpioUart& rx, GpioUart& tx);
    uint32_t getBase(void);
    void enable(uint32_t baudrate, uint32_t config, uint32_t mode);
    void sleep(void);
    void wakeup(void);
    void setRxCallback(Callback* callback);
    void setTxCallback(Callback* callback);
    void enableInterrupts(void);
    void disableInterrupts(void);
    uint8_t readByte(void);
    uint32_t readByte(uint8_t* buffer, uint32_t length);
    void writeByte(uint8_t byte);
    uint32_t writeByte(uint8_t* buffer, uint32_t length);
protected:
    void interruptHandler(void);
private:
    void interruptHandlerRx(void);
    void interruptHandlerTx(void);
private:
    uint32_t peripheral_;
    uint32_t base_;
    uint32_t clock_;
    uint32_t interrupt_;
    uint32_t mode_;
    uint32_t config_;
    uint32_t baudrate_;

    GpioUart& rx_;
    GpioUart& tx_;

    Callback* rx_callback_;
    Callback* tx_callback_;
};

#endif /* UART_H_ */
