#include "include/global.h"
#include "include/keypresses.h"

const char* CLEAR_SCREEN = "\033[2J\033[H";
struct Global_Buffer *p_global_buffer = NULL;
enum MODE GLOBAL_MODE = NORMAL;
const unsigned int MAX_ROW_LEN = 1000;
