#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "keypresses.h"
#include "buffer.h"
#define PAGE_MAX_LEN 100
#define PADE_MAX_COL 100

#define ACTIVE_BUFFER p_global_buffer->active_buffer
#define ESC 27
#define BACKSPACE 38
#define ENTER 39
#define i 105
#define I 73


#define CHECK_FOR_NULL(n) \
    if(n == NULL) {\
    printf("Null at %d in %s", __LINE__, __FILE__);\
    exit(1);\
}


#define CHECK_FOR_NULL_OR_RETURN(n) \
    if(n == NULL) {\
    printf("Null at %d in %s \n", __LINE__, __FILE__);\
    return false;\
}


extern enum MODE GLOBAL_MODE;
extern struct global_buffer* p_global_buffer;
extern const char* CLEAR_SCREEN;
extern const char* REFRESH_SCREEN;
extern const unsigned int MAX_ROW_LEN;

#endif
