#include "include/keypresses.h"
#include "include/global.h"
#include "include/buffer.h"
#include <termios.h>

// I can add a function pointer that will render the updates
void process_insert_mode_keypress(char c) {
    switch (c) {
        case ESC:
            GLOBAL_MODE = NORMAL;
            break;
        default:
            write_to_file_buffer(c);
    }
}

void process_normal_mode_keypress(char c) {
    switch (c) {
        case i:
        case I:
            GLOBAL_MODE = INSERT;
            break;
        case CTRL('q'):
            exit(0);
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
