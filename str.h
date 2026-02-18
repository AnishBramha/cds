#include "./vector.h"

#define NIL '\0'

typedef vector* string;

string str_new(void);
string str_from_char_array(const char*, const int size);
void str_append(string, const char);
char str_get(const string, const int idx);
const char* str_extract(const string);
string str_slice(const string, const int start, const int end);
void str_concat(string src, const string extra);
void str_delete(string);







