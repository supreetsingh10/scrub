#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <sys/types.h>
#include <stdbool.h>

#define ROWS 1000
typedef char* buffer;

struct Global_Buffer {
    // Array of file_buffers
    struct File_Buffer* p_file_buffer;
    u_int total_buffers;
    u_int active_buffer;
};

struct File_Buffer {
    buffer* p_buffer;
    char* p_buffer_name;

    u_int cur_row;
    u_int cur_col;
    u_int written_rows;
};

bool init_global_file_buffer(u_int file_nums, char** file_names);
bool write_to_buffer(const char c);

#endif
