#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;
    printf("Type a size of memory: ");
    scanf("%d", &num);
    int *ptr = (int *)malloc(num * sizeof(int));

    if (ptr == NULL) {
        printf("Ops! Memory full");
        exit(1);
    }

    for (size_t i=0; i<num; i++) {
        printf("Type the number to be allocated: ");
        scanf("%d", ptr+i);
    }

    for (size_t i=0; i<num; i++) {
        printf("The number you sent and the correspondent address: ");
        printf("%d %d\n", *(ptr+i), ptr+i);
    }

    free(ptr);
    return 0;
}