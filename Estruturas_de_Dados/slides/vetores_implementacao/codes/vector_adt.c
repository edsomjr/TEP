#include <stdlib.h>
#include "vector_adt.h"

typedef struct _vector {
    int *data;
    int size;
    int capacity;
} pvector;

vector create_vector(int capacity)
{
    if (capacity < 1) return NULL;

    pvector *pv = (pvector *) calloc(1, sizeof(pvector));

    if (!pv) return NULL;

    pv->capacity = capacity;
    pv->data = (int *) malloc(capacity * sizeof(int));

    if (!pv->data) {
        free(pv);
        return NULL;
    }

    return (vector) pv;
}

void free_vector(vector v)
{
    pvector *pv = (pvector *) v;

    if (!pv)
        return;

    if (pv->data)
        free(pv->data);

    free(pv);
}

#include "vector_errors.h"

int element_at(const vector v, int index)
{
    const pvector *pv = (const pvector *) v;

    if (!pv)
        return VECTOR_ERROR_NULL_PARAMETER;

    if (index < 0 || index >= pv->size)
        return VECTOR_ERROR_INDEX_OUT_OF_BOUNDS;

    return pv->data[index];
}

int size(const vector v)
{
    const pvector *pv = (const pvector *) v;

    return pv ? pv->size : VECTOR_ERROR_NULL_PARAMETER;
}

int push_back(vector v, int value) {
    pvector *pv = (pvector *) v;
    int i, *p;

    if (!pv) return VECTOR_ERROR_NULL_PARAMETER;

    if (pv->size == pv->capacity) {
        if (!(p = (int *) malloc(2 * pv->capacity * sizeof(int))))
            return VECTOR_ERROR_OUT_OF_MEMORY;

        for (i = 0; i < pv->size; ++i)
            p[i] = pv->data[i];

        free(pv->data);
        pv->data = p;
        pv->capacity *= 2;
    }

    pv->data[pv->size++] = value;
    return VECTOR_OK;
}

int push(vector v, int value, int index) {
    pvector *pv = (pvector *) v;
    int i;

    if (!pv) return VECTOR_ERROR_NULL_PARAMETER;

    if (index < 0 || index >= pv->size) 
        return VECTOR_ERROR_INDEX_OUT_OF_BOUNDS;        

    if (pv->size == pv->capacity) {
        if ((i = push_back(v, value)) != VECTOR_OK) return i;
        pv->size--;
    }

    for (i = pv->size; i >= index; --i)
        pv->data[i] = pv->data[i - 1];

    pv->data[index] = value;
    pv->size++;    
    return VECTOR_OK;
}

int pop_back(vector v) {
    pvector *pv = (pvector *) v;

    if (!pv) return VECTOR_ERROR_NULL_PARAMETER;

    if (pv->size == 0) return VECTOR_ERROR_EMPTY_VECTOR;

    pv->size--;

    return VECTOR_OK;
}

int clear(vector v) {
    pvector *pv = (pvector *) v;

    if (!pv) return VECTOR_ERROR_NULL_PARAMETER;

    pv->size = 0;

    return VECTOR_OK;
}

int pop(vector v, int index)
{
    pvector *pv = (pvector *) v;
    int i;

    if (!pv) return VECTOR_ERROR_NULL_PARAMETER;

    if (pv->size == 0) return VECTOR_ERROR_EMPTY_VECTOR;

    if (index < 0 || index >= pv->size) 
        return VECTOR_ERROR_INDEX_OUT_OF_BOUNDS;        

    for (i = index + 1; i < pv->size; ++i)
        pv->data[i - 1] = pv->data[i];

    --pv->size;

    return VECTOR_OK;
}
