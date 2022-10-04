#include <float.h>
#include <float_vector.h>

float min(const FloatVector *v) {
    float m = FLT_MAX;

    for (int i = 0; i < v->size; ++i)
        m = v->data[i] < m ? v->data[i] : m;

    return m;
}

float max(const FloatVector *v) {
    float m = -FLT_MAX;

    for (int i = 0; i < v->size; ++i)
        m = v->data[i] > m ? v->data[i] : m;

    return m;
}
