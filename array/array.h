typedef struct {
    int capacity;
    int used;
    int* data;
} Array;

Array* init_array();

int array_push(Array* array, int value);
int array_pop(Array* array);
int array_get(Array* array, int index);
