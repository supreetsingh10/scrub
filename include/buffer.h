#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <sys/types.h>
#include <stdbool.h>

#define ROWS 1000
typedef char* buffer;

struct Global_Buffer {
    struct File_Buffer** p_fbuffer;
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

bool Init_Global_File_Buffer(u_int file_nums, char** file_names);
bool write_to_buffer(const char c);

static bool Init_File_Buffer(struct File_Buffer*** f, const u_int buf_nums, char** file_names);

#endif
