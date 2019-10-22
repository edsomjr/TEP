#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

typedef struct _FloatVector {
    float *data;
    int size;
} FloatVector;

extern float max(const FloatVector *v);
extern float min(const FloatVector *v);

#endif
