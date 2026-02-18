#include "./str.h"
#include <assert.h>

string str_new(void) {

    string str = v_new(char);
    v_push(str, char, NIL);

    return str;
}

string str_from_char_array(const char* str, const int size) {

    string s = v_from_array(str, char, size);
    v_push(s, char, NIL);

    return s;
}

void str_append(string str, const char c) {

    assert(str->size > 0);
    str->size--;

    v_push(str, char, c);
    v_push(str, char, NIL);

    return;
}

char str_get(const string str, const int idx) {

    return *v_get(str, char, idx);
}

const char* str_extract(const string str) {

    return (const char*)str->items; 
}

void str_delete(string str) {
    
    v_delete(str);
    return;
}

string str_slice(const string str, const int start, const int end) {

    string slice = v_slice(str, start, end);
    v_push(slice, char, NIL);
    return slice;
}

void str_concat(string src, const string extra) {

    const char* str = str_extract(extra);

    for (size_t i = 0; i < extra->size - 1; i++)
        str_append(src, str[i]);

    return;
}




