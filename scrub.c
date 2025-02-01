#include <assert.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <sys/types.h>
#include <termio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "include/keypresses.h"
#include "include/buffer.h"
#include "include/global.h"

bool enable_raw_mode() {
    struct termios t;
    cfmakeraw(&t);
    return tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
}

static void clear_screen() {
    write(STDIN_FILENO, CLEAR_SCREEN, strlen(CLEAR_SCREEN));
}

bool get_term_window_size(struct winsize* w) {
    return ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
}


int main(int argc, char** argv) {
    if(enable_raw_mode() != 0)
        printf("Failed to enter the raw mode");

    clear_screen();

    if(!init_global_file_buffer(argc, argv)) {
        printf("Failed to Initialize the Global file buffer");
        return 1;
    }

    CHECK_FOR_NULL(p_global_buffer);
    CHECK_FOR_NULL(p_global_buffer->p_file_buffer);

    char c;
    while (true) {
        if(read(STDIN_FILENO, &c, sizeof c) > 0) {
            process_keypresses(c);
        }
    }

    return 0;
}
