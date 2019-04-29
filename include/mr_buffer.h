
#ifndef __mr_buffer_h__
#define __mr_buffer_h__

#include <stdint.h>
#include <stdlib.h>

struct mr_buffer {
	size_t size;
	size_t offset;
	struct mr_buffer_node *head;
	struct mr_buffer_node *tail;

	int head_len;
	int pack_len;

	int read_len;
	int read_cap;
	char* read_data;

	int write_len;
	int write_cap;
	char* write_data;
};


#define mr_buffer_size(buffer) (buffer)->size

// static inline size_t mr_buffer_size(struct mr_buffer* buffer){
// 	return buffer->size;
// }

struct mr_buffer* mr_buffer_create(int head_len);
void mr_buffer_free(struct mr_buffer* buffer);
int mr_buffer_read_push(struct mr_buffer* buffer, char* msg, size_t len);
int mr_buffer_read_header(struct mr_buffer* buffer, size_t len);
int mr_buffer_read(struct mr_buffer* buffer, char* data, int len);
int mr_buffer_read_pack(struct mr_buffer* buffer);
int mr_buffer_write_pack(struct mr_buffer* buffer, char* data, size_t len);


#endif