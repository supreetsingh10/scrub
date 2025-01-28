#include "include/buffer.h"
#include "include/global.h"
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>

#define ACTIVE_BUFFER p_global_buffer->active_buffer

// this will be taking the command line arguments.
bool Init_Global_File_Buffer(u_int file_nums, char** file_names) {
    p_global_buffer = (struct Global_Buffer*)malloc(sizeof(struct Global_Buffer));
    p_global_buffer->active_buffer = 0;
    p_global_buffer->total_buffers = file_nums;

    CHECK_FOR_NULL(p_global_buffer);

    return Init_File_Buffer(&p_global_buffer->p_fbuffer, p_global_buffer->total_buffers, file_names);
}


bool Init_File_Buffer(struct File_Buffer ***file_buffer, const u_int file_nums, char** file_names) {
    file_buffer = (struct File_Buffer***)calloc(file_nums, sizeof(struct File_Buffer));
    CHECK_FOR_NULL_AND_RETURN(file_buffer);

    if(file_nums == 1) {
    } else {

    }

    return true;
}

bool write_to_buffer(const char c) {
    return false;
}
