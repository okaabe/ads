#include <array.h>
#include <stdlib.h>
#include <stdio.h>

Array* init_array() {
    Array* array = malloc(sizeof(Array));

    array -> capacity = 8;
    array -> used = 0;
    array -> data = malloc(array -> capacity * sizeof(int));

    return array;
}

int dynamic_array_handling(Array* array) {
    if (array -> capacity >= array -> used) {
        array -> capacity = array -> capacity * 3;
        array -> data = realloc(array -> data, (size_t) array -> capacity * sizeof(int));

        return 1;
    }

    return 0;
}

int dynamic_array_pop_handling(Array* array) {
    if (array->used-1 < array->capacity*2/3){
        array->capacity = array->capacity*2/3;
        array->data = realloc(array->data, array->capacity);

        return 1;
    }

    return 0;
}

int array_push(Array* array, int value) {
    dynamic_array_handling(array);
    array -> data[array -> used] = value;
    array -> used += 1;
}

int array_pop(Array* array) {
    dynamic_array_pop_handling(array);

    array -> used -= 1;

    return array -> data [array -> used - 1];
}

int array_get(Array* array, int index) {
    if (array -> used <= index) {
        printf("Index out of bounds");
        return 0;       
    }

    return array -> data[index];
}
