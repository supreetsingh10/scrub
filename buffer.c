#include "include/buffer.h"
#include "include/global.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>


// this will be taking the command line arguments.
bool init_global_file_buffer(u_int file_nums, char** file_names) {
    p_global_buffer = (struct Global_Buffer*)malloc(sizeof(struct Global_Buffer));
    p_global_buffer->active_buffer = 0;
    p_global_buffer->total_buffers = file_nums;

    CHECK_FOR_NULL_OR_RETURN(p_global_buffer);

    p_global_buffer->p_file_buffer = (struct File_Buffer*)calloc(file_nums, sizeof(struct File_Buffer));
    CHECK_FOR_NULL_OR_RETURN(p_global_buffer->p_file_buffer);

    for(size_t fs = 0; fs < file_nums; fs++) {
        struct File_Buffer *f = &p_global_buffer->p_file_buffer[fs];

        f->p_buffer_name = (char *) malloc(sizeof(file_names[fs]));
        CHECK_FOR_NULL_OR_RETURN(f->p_buffer_name);
        strcpy(f->p_buffer_name, file_names[fs]);

        f->cur_col = 0;
        f->cur_row = 0;

        f->p_buffer = (char **)malloc(sizeof(char));
        // TODO
        // this is a array of strings;
        // I will need a function for file initialization
        // for now just keep it as a new file
    }

    return true;
}

bool write_to_buffer(const char c) {
    struct File_Buffer* f = &p_global_buffer->p_file_buffer[ACTIVE_BUFFER];
    CHECK_FOR_NULL_OR_RETURN(f);
    CHECK_FOR_NULL(f->p_buffer);

    if(f->p_buffer[f->cur_row] == NULL) {
        f->p_buffer[f->cur_row] = (buffer) calloc(MAX_ROW_LEN, sizeof(char));
    }

    f->p_buffer[f->cur_row][f->cur_col] = c;

    // testing something here
    if(write(STDOUT_FILENO, f->p_buffer, sizeof(f->p_buffer)) == -1) {
        exit(1);
    }

    return true;
}
