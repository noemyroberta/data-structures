#include <stdio.h>
struct array {
    int capacity;
    int size;
    int v[];
};

void push(int i, struct array arr[]) {
    if (arr->size == arr->capacity) {
        int newArray[2*arr->capacity];
        for (int j=0; j < arr->size-1; j++) {
            newArray[j] = arr->v[j];
        }
    }
    arr->v[arr->size] = i;
    arr->size = arr->size + 1;
}

int main(void)
{
    struct array arr;
    arr.capacity = 2;
    arr.size = 0;
    arr.v[arr.capacity];
    
    return 0;
}