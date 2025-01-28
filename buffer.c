#include "include/buffer.h"
#include "include/global.h"
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>

#define ACTIVE_BUFFER p_global_buffer->active_buffer

// this will be taking the command line arguments.
bool init_global_file_buffer(u_int file_nums, char** file_names) {
    p_global_buffer = (struct Global_Buffer*)malloc(sizeof(struct Global_Buffer));
    p_global_buffer->active_buffer = 0;
    p_global_buffer->total_buffers = file_nums;

    CHECK_FOR_NULL(p_global_buffer);

    p_global_buffer->p_fbuffer = calloc(file_nums, sizeof(struct File_Buffer));

    // check for the variables.

    return true;
}



bool write_to_buffer(const char c) {
    return false;
}
