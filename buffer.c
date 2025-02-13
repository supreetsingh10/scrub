#include <stdio.h>
#include "include/buffer.h"
#include "include/global.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>


// this will be taking the command line arguments.
bool init_global_file_buffer(u_int file_nums, char** file_names) {
    p_global_buffer = (struct global_buffer*)malloc(sizeof(struct global_buffer));
    p_global_buffer->active_buffer = 0;
    p_global_buffer->total_buffers = file_nums;

    CHECK_FOR_NULL_OR_RETURN(p_global_buffer);

    p_global_buffer->p_file_buffers = (struct file_buffer*)calloc(file_nums + 1, sizeof(struct file_buffer));
    CHECK_FOR_NULL_OR_RETURN(p_global_buffer->p_file_buffers);

    for(size_t fn = 1; fn < file_nums; fn++) {
        struct file_buffer *fb = &p_global_buffer->p_file_buffers[fn];
        fb->cur_col = 0;
        fb->cur_row = 0;
        fb->written_rows = 0;
        fb->p_buffer_name = malloc(strlen(file_names[fn]) + 1);
        strcpy(fb->p_buffer_name, file_names[fn]);


        fb->text_lines = (struct text_line**) malloc(100 * sizeof(struct text_line *));
        init_file_buffer(&fb, file_names[fn]);
    }

    return true;
}

bool init_file_buffer(struct file_buffer** p_fb, const char* file_name) {
    int fd = open(file_name, O_RDONLY | O_CREAT);

    if(fd == -1)
        return false;
    // Now read through the file line by line
    // populate the file_buffer
    // read returns.

    struct file_buffer* fb = *(p_fb);
    fb->written_rows += 1;

    INIT_TEXT_LINE(fb->text_lines[fb->cur_row]);

    char ch;
    while(read(fd, &ch, sizeof ch) > 0) {
        struct text_node *n = malloc(sizeof(struct text_node));
        INIT_TEXT_NODE(n);
        n->value = ch;

        append_to_line(n, fb->text_lines[fb->cur_row]);

        if(ch== '\n') {
            fb->written_rows += 1;
            fb->cur_row += 1;
            INIT_TEXT_LINE(fb->text_lines[fb->cur_row]);
        }
    }

    fb->cur_row = 0;
    return true;
}

bool write_to_file_buffer(const char c) {
    struct file_buffer* f = &p_global_buffer->p_file_buffers[ACTIVE_BUFFER];
    CHECK_FOR_NULL(f);

    struct text_line *line = f->text_lines[f->cur_row];
    CHECK_FOR_NULL(line);


    struct text_node* iter = NULL;
    switch (c) {
        case BACKSPACE:
            break;
        case ENTER:
            // go to the next row
            f->cur_row += 1;
            break;
        default:
            // I need to map the location of the cursor to the text nodes I am working with
            break;
    }

    return true;
}

bool test_print_the_file(struct file_buffer* fb) {
    for(u_int rows = 0; rows < fb->written_rows; rows++) {
        struct text_line* line = fb->text_lines[rows];

        struct text_node* temp = line->head;

        while(temp != NULL) {
            printf("%c", (char)temp->value);
            temp = temp->next;
        }
    }

    return true;
}
