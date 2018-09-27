#include <float.h>
#include <float_vector.h>

float limits(const FloatVector *v, char limit) {
    register int i;
    float a = -FLT_MAX, b = FLT_MAX;
    
    for (i = 0; i < v->size; i++) {
        a = (v->data[i] > a ? v->data[i] : a);
        b = (v->data[i] < b ? v->data[i] : b);
    }
    return (limit == 'a' ? a : b);
}

float min(const FloatVector *v) {
    return limits(v, 'a');
}

float max(const FloatVector *v) {
    return limits(v, 'b');
}
