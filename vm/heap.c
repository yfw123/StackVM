#include "heap.h"
#include <stdio.h>

HEAP heap_from(CONSTANTS constants, size_t min_writable_size)
{
    size_t chunk_headers_size = sizeof(CHUNK) * 2;
    size_t size               = chunk_headers_size + constants.length + min_writable_size;

    CHUNK* constants_chunk    = (CHUNK*)malloc(size);
    constants_chunk->previous = NULL;
    constants_chunk->next     = NULL;
    constants_chunk->size     = constants.length;
    constants_chunk->flags    = CHUNK_READONLY;
    char* data                = (char*)constants_chunk + sizeof(CHUNK);
    memcpy(data, constants.data, constants.length);

    CHUNK* writable_chunk    = (CHUNK*)((char*)constants_chunk) + sizeof(CHUNK) + constants.length;
    writable_chunk->next     = NULL;
    writable_chunk->previous = constants_chunk;
    writable_chunk->size     = min_writable_size;
    writable_chunk->flags    = 0;

    constants_chunk->next = writable_chunk;

    HEAP heap;
    heap.size  = size;
    heap.start = (char*)constants_chunk;

    return heap;
}

void heap_free(HEAP heap)
{
    free(heap.start);
}

void heap_dump(HEAP heap)
{
    int chunk_counter = 0;

    CHUNK* current = (CHUNK*)heap.start;
    for (;;) {
        if (current == NULL) {
            break;
        }

        printf("Chunk #%i (Flag: %i, size: %i):\n", chunk_counter, current->flags, current->size);

        char* data = (char*)current + sizeof(CHUNK);
        for (int i = 0; i < current->size; i++) {
            printf("%i\n", data[i]);
        }
        chunk_counter++;
        current = current->next;
    }
}