#include <stdlib.h>
#include "vector.h"

vector * create_vector(int capacity)
{
    if (capacity < 1) return NULL;

    vector *v = (vector *) calloc(1, sizeof(vector));

    if (!v) return NULL;

    v->capacity = capacity;
    v->data = (int *) malloc(capacity * sizeof(int));

    if (!v->data) {
        free(v);
        return NULL;
    }

    return v;
}

void free_vector(vector *v)
{
    if (!v)
        return;

    if (v->data)
        free(v->data);

    free(v);
}
