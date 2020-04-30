#ifndef C_VECTOR_ADT_H
#define C_VECTOR_ADT_H

typedef void * vector;

extern vector create_vector(int capacity);
extern void free_vector(vector v);
extern int element_at(const vector v, int index);
extern int size(const vector v);

extern int push(vector v, int value, int index);
extern int push_back(vector v, int value);
extern int pop(vector v, int index);
extern int pop_back(vector v);
extern int clear(vector v);

#endif
