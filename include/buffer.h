#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <sys/types.h>
#include <stdbool.h>

#define ROWS 1000

// ptrs to right and left
// len
// char c;

#define container_of(ptr, type, member) ({ \
const typeof( ((type *)0)->member)) *__mptr = ptr;\
(type *)( (char *)__mptr - offsetof(type, member));})

// ptr should be malloced.
#define iterate_from_front(iter, line_ptr, index) \
iter = line_ptr->node; \
int count = 0; \
while(iter != NULL && count != index) {\
iter = iter->next;\
++count;\
}

#define iterate_from_back(iter, line_ptr, index) \
iter = line_ptr->tail;\
int count = 0;\
while(line_ptr->len - count != index && iter != NULL) {\
iter = iter->prev;\
count++;\
}

#define iterate_to_index(ptr, line_ptr, index) \
if(line_ptr->len - index < index) { \
(iterate_from_back(ptr, line_ptr, index))\
} else { \
(iterate_from_front(ptr, line_ptr, index))\
}

#define INIT_TEXT_LINE(p_text_line) \
p_text_line = malloc(sizeof (struct text_line)); \
p_text_line->head = NULL; \
p_text_line->tail = NULL; \
p_text_line->len = 0; \

#define INIT_TEXT_NODE(p_text_node) \
p_text_node = malloc(sizeof (struct text_node)); \
p_text_node->prev = NULL; \
p_text_node->next = NULL; \


#define append_to_line(node, line_ptr) \
if (line_ptr->head == NULL) {\
line_ptr->head = node; \
line_ptr->tail = node; \
line_ptr->head->prev = NULL; \
line_ptr->head->next = NULL; \
} \
else { \
node->prev = line_ptr->tail; \
node->next = NULL; \
line_ptr->tail->next = node;\
line_ptr->tail = line_ptr->tail->next;\
} \
line_ptr->len += 1;


struct global_buffer {
    // Array of file_buffers
    struct file_buffer* p_file_buffers;
    u_int total_buffers;
    u_int active_buffer;
};

struct text_node {
    struct text_node *prev, *next;
    char value;
};

struct text_line {
    struct text_node* head;
    // this will have the first node and the last node in the list. 
    // Will make it easier to push and pop nodes.
    // this will be for the line
    struct text_node *tail;
    size_t len;
};


// text_node** text_line
// cur_row, cur_col
struct file_buffer {
    struct text_line** text_lines;
    char* p_buffer_name;

    u_int cur_row;
    u_int cur_col;
    u_int written_rows;
};

bool init_global_file_buffer(u_int file_nums, char** file_names);
bool write_to_file_buffer(const char c);
static bool init_file_buffer(struct file_buffer** p_fb, const char* file_name);

// this has successfully passed.
static bool test_print_the_file(struct file_buffer* fb);
#endif
