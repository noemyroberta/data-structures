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

show(struct array *v) {
    printf("Capacity: %d ", v->capacity);
    printf("Size: %d ", v->size);
    printf("Values: ");
    for (int i = 0; i < v->capacity; i++) {
        printf("%d ", *(v->arr + i));
    }
    printf("\n");
}

int get(int index, struct array *v) {
    if (index < 0 || index >= v->capacity) {
        return -1;
    }
    return *(v->arr+index);
}

int main(void) {
    struct array v;
    v.capacity = 2;
    v.size = 0;
    v.arr = (int *)calloc(v.capacity, sizeof(int));
    push(12, &v);
    push(13, &v);
    push(14, &v);
    show(&v);
    int val = get(1, &v);
    if (val == -1) {
        printf("\nIndex out of range, response: %d\n", val);
    } else {
        printf("\nGetted value: %d\n", val);
    }
    free(v.arr);
    return 0;
}
