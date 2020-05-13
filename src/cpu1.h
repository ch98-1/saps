#ifndef CPU1_H
#define CPU1_H

#include <stdlib.h>

#include "common.h"

//cpu simulator. takes in the memory, runs the specified number of cycles, and outputs 0 on success.
//directly modifies the memory values goven
int cpu1(uint16_t* rf, uint16_t* im, uint16_t* dm, uint32_t cycles);

#endif /* CPU1_H */
