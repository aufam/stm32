#ifndef __EE_H__
#define __EE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t ee_write(const uint8_t* data, uint32_t len, uint32_t address);

#ifdef __cplusplus
}
#endif
#endif

