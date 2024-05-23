#include <stdio.h>
#include <stdlib.h>

struct array {
    int capacity;
    int size;
    int *arr;
};

void push(int value, struct array *v) {
    if (v->size == v->capacity) {
        v->capacity = 2 * v->capacity;
        v->arr = (void *)realloc(v->arr, v->capacity);
    }
    v->arr[v->size] = value;
    v->size++;
}

int isEmpty(struct array *v) {
    return v->size == 0;
}

int capacity(struct array *v) {
    return v->capacity;
}

int size(struct array *v) {
    return v->size;
}

void show(struct array *v) {
    printf("Capacity: %d ", v->capacity);
    printf("Size: %d ", v->size);
    printf("Values: ");
    for (int i = 0; i < v->capacity; i++) {
        printf("%d ", *(v->arr + i));
    }
    printf("\n");
}

int pop(struct array *v) {
    if (isEmpty(v)) {
        return -1;
    }
    int lastIndex = v->size-1;
    int lastValue = *(v->arr+lastIndex); 
    *(v->arr+lastIndex) = 0;
    v->size--;
    return lastValue;
}

int at(int index, struct array *v) {
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
    //push(13, &v);
    //push(14, &v);
    show(&v);
    int val = at(1, &v);
    if (val == -1) {
        printf("\nIndex out of range, response: %d\n", val);
    } else {
        printf("\nGetted value: %d\n", val);
    }
    int lastValue = pop(&v);
    if (lastValue == -1) {
        printf("The heap is empty!");
    } else {
        printf("Last value: %d", lastValue);
    }
    show(&v);
    free(v.arr);
    return 0;
}
