#ifndef __BLINKY_H__
#define __BLINKY_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern char blinky_symbols[];
extern int blinky_is_running;
extern uint32_t blinky_delay;

#ifdef __cplusplus
}
#endif

#endif
