#ifndef __KEYPRESS_H__
#define __KEYPRESS_H__

#include <termio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

enum MODE {
    NORMAL,
    INSERT,
    SEARCH,
};

static void process_keypress_as_per_mode(char c);
static void process_normal_mode_keypress(char c);
static void process_insert_mode_keypress(char c);
static void process_search_mode_keypress(char c);

void process_keypresses(const char c);

#endif
