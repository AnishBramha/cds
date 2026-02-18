#include "./vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void* alloc(size_t size) {

    void* mem = malloc(size);
    assert(mem);
    return mem;
}

vector* _v_new(const int elem_size) {

    assert(elem_size > 0);

    vector* v = alloc(sizeof(vector)); 
    v->size = 0;
    v->capacity = 8;
    v->elem_size = elem_size;
    assert(v->items = alloc(v->capacity * elem_size));

    return v;
}

vector* _v_from_array(const void* array, const int size, const int len) {

    assert(size > 0 && len > 0);

    vector* v = alloc(sizeof(vector));
    v->size = len;
    v->capacity = len * 2;
    v->elem_size = size;
    assert(v->items = alloc(v->capacity * size));

    memcpy(v->items, array, len * size);

    return v;
}

void _v_push(vector* v, const void *elem) {

    assert(v);

    if (v->size == v->capacity) {

        v->capacity *= 2;
        assert(v->items = realloc(v->items, v->capacity * v->elem_size)); 
    }

    char* t_addr = (char*)v->items + (v->size++ * v->elem_size);
    memcpy(t_addr, elem, v->elem_size);

    return;
}

void* _v_get(const vector* v, const int idx) {

    assert(v && idx >= 0 && idx < v->size);

    return (char*)v->items + (idx * v->elem_size);
}

void v_display(const vector* v, void (*render)(void*)) {

    assert(v && render);

    putchar('[');

    size_t i = 0;
    for (; i < v->size - 1; i++) {

        render(_v_get(v, i));
        putchar(',');
    }
    
    render(_v_get(v, i));
    puts("]");

    return;
}

void v_delete(vector* v) {

    assert(v && v->items);

    free(v->items);
    free(v);

    return;
}

vector* v_slice(const vector* v, const int start, const int end) {

    assert(v && start >= 0 && end < v->size && start <= end);

    char* t_addr = (char*)v->items + (v->elem_size * start);
    return _v_from_array(t_addr, v->elem_size, end - start + 1);
}






