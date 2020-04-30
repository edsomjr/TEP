#ifndef C_VECTOR_H
#define C_VECTOR_H

typedef struct _vector {
    int *data;
    int size;
    int capacity;
} vector;

extern vector * create_vector(int capacity);
extern void free_vector(vector *v);
extern int element_at(vector *v, int index);
extern int size(vector *v);

extern int push(vector *v, int value, int index);
extern int push_back(vector *v, int value);
extern int pop(vector *v, int index);
extern int pop_back(vector *v);
extern void clear(vector *v);

#endif
