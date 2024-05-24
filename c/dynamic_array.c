#include <stdio.h>
#include <stdlib.h>

struct array {
  int capacity;
  int size;
  int *arr;
};

int isFull(struct array *v) { return v->size == v->capacity; }

int isOutOfRange(int index, struct array *v) {
  return index < 0 || index >= v->capacity;
}

int isEmpty(struct array *v) { return v->size == 0; }

int capacity(struct array *v) { return v->capacity; }

int size(struct array *v) { return v->size; }

void push(int value, struct array *v) {
  if (isFull(v)) {
    v->capacity = 2 * v->capacity;
    v->arr = (void *)realloc(v->arr, v->capacity);
  }
  v->arr[v->size] = value;
  v->size++;
}

int insert(int index, int value, struct array *v) {
  if (isFull(v)) {
    return -1;
  } else if (*(v->arr + index) != 0) {
    for (size_t i = v->size; i > index; i--) {
      v->arr[i] = v->arr[i-1];
    }
  }
  v->arr[index] = value;
  v->size++;
  return 0;
}

void show(struct array *v) {
  printf("\n");
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
  int lastIndex = v->size - 1;
  int lastValue = *(v->arr + lastIndex);
  *(v->arr + lastIndex) = 0;
  v->size--;
  return lastValue;
}

int at(int index, struct array *v) {
  if (isOutOfRange(index, v)) {
    return -1;
  }
  return *(v->arr + index);
}

int delete(int index, struct array *v) {
  if (isOutOfRange(index, v)) {
    return -1;
  } else if (index != v->size - 1) {
    for (size_t i = index; i < v->size; i++) {
      v->arr[i] = v->arr[i + 1];
    }
  }
  *(v->arr + v->size - 1) = 0;
  v->size--;
  return 0;
}

int removeValue(int value, struct array *v) {
  if (isEmpty(v)) {
    return -1;
  }
  for (size_t i = 0; i < v->capacity; i++) {
    if (*(v->arr + i) == value) {
      *(v->arr + i) = 0;
      v->size--;
    }
  }
  return 0;
}

int findValue(int value, struct array *v) {
  if (isEmpty(v)) {
    return -1;
  }
  for (size_t i = 0; i < v->size; i++) {
    if (*(v->arr + i) == value) {
      return i;
    }
  }
  return -1;
}

int prepend(int value, struct array *v) {
  return insert(0, value, v);
}

int main(void) {
  struct array v;
  v.capacity = 2;
  v.size = 0;
  v.arr = (int *)calloc(v.capacity, sizeof(int));
  push(13, &v);
  push(23, &v);
  push(43, &v);
  show(&v);
  int result = insert(3, 43, &v);
  printf("\ninsert result %d", result);
  show(&v);
  printf("\nf %d", findValue(43, &v));
  removeValue(43, &v);
  show(&v);
  printf("\nr %d", removeValue(43, &v));
  printf("\nf %d", findValue(43, &v));
  free(v.arr);
  return 0;
}
