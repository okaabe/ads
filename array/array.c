#include <array.h>
#include <stdlib.h>

Array* init_array() {
    Array* array = malloc(sizeof(Array));

    array -> capacity = 8;
    array -> used = 0;
    array -> data = malloc(array -> capacity * sizeof(int));

    return array;
}

/**
 * 0 = it wasn't necessary extend the array size
 * 1 = it was necessary extend the array size
 * **/
int dynamic_array_handling(Array* array) {
    if (array -> capacity >= array -> used) {
        array -> capacity = array -> capacity * 3;
        array -> data = realloc(array -> data, (size_t) array -> capacity * sizeof(int));

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

}