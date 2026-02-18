#pragma once

#include <stddef.h>

typedef struct {

    void* items;
    size_t size;
    size_t capacity;
    size_t elem_size;

} vector;

vector* _v_new(const int elem_size);
vector* _v_from_array(const void* array, const int size, const int len);
void _v_push(vector*, const void* elem);
void* _v_get(const vector*, const int idx);
void v_display(const vector*, void(*)(void*));
vector* v_slice(const vector*, const int start, const int end);
void v_delete(vector*);


#define v_new(type) _v_new(sizeof(type))
#define v_from_array(array, type, len) _v_from_array(array, sizeof(type), len)

#define v_push(v, type, elem) \
    do { \
        type temp = (elem); \
        _v_push(v, &temp); \
    } while(0)


#define v_get(vec, type, idx) (type*)_v_get(vec, (idx))



        




