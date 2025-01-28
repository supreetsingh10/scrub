#include "include/keypresses.h"
#include "include/global.h"

enum MODE GLOBAL_MODE;

bool initialize() {
    GLOBAL_MODE = NORMAL;
    return true;
}

void process_insert_mode_keypress(char c) {
    switch (c) {
        case ESC:
        GLOBAL_MODE = NORMAL;
        break;
    }
}

void process_normal_mode_keypress(char c) {
    switch (c) {
        case i:
        case I:
            GLOBAL_MODE = INSERT;
            break;
    }
}

// TODO
void process_search_mode_keypress(char c) {

}

void process_keypress_as_per_mode(char c) {
    switch (GLOBAL_MODE) {
        case NORMAL:
            process_normal_mode_keypress(c);
            break;
        case INSERT:
            process_insert_mode_keypress(c);
            break;
        case SEARCH:
            process_search_mode_keypress(c);
            break;
      break;
    }
}

void process_keypresses(const char c)
{
    process_keypress_as_per_mode(c);
}
