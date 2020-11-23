#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

vec_ptr new_vec(int len) {
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result) 
        return NULL;
    result->len = len;

    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void*) result);
            return NULL;
        }
    }
    result->data = data;
    return result;
}

int get_vec_element(vec_ptr v, long index, data_t *dest) {
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}

long vec_length(vec_ptr v) {
    return v->len;
}

void combine1(vec_ptr v, data_t *dest) {
    int i;

    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OPER val;
    }
}

void combine2(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OPER val;
    }
}

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}

void combine3(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        *dest = *dest OPER data[i];
    }
}

void combine4(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t x = IDENT;

    for (i = 0; i < length; i++) {
        x = x OPER data[i];
    }
    *dest = x;
}