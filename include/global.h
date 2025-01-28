#ifndef __GLOBAL_H__
#define __GLOBAL_H__


#include "keypresses.h"
#include "buffer.h"
#define PAGE_MAX_LEN 100
#define PADE_MAX_COL 100

extern enum MODE GLOBAL_MODE;
extern struct Global_Buffer* p_global_buffer;

#define ESC 27
#define i 105
#define I 73

extern const char* CLEAR_SCREEN;

#define CHECK_FOR_NULL(n) \
    if(n == NULL) {\
    printf("Null at %d", __LINE__);\
    exit(1);\
}\

#define CHECK_FOR_NULL_AND_RETURN(n) \
    if(n == NULL) {\
    printf("Null at %d", __LINE__);\
    return false;\
}\


#endif
