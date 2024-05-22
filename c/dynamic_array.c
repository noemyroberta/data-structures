#include <stdio.h>
#include <stdlib.h>

struct array {
    int capacity;
    int size;
    int *arr;
}

push(int value, struct array *v) {
    if (v->size == v->capacity) {
        v->capacity = 2 * v->capacity;
        v->arr = (void *)realloc(v->arr, v->capacity);        
    }
    v->arr[v->size] = value;
    v->size++; 
}

int main(void) {
    struct array v;
    v.capacity = 2;
    v.size = 0;
    v.arr = (int *)calloc(v.capacity, sizeof(int));

    free(v.arr);
    return 0;
}
