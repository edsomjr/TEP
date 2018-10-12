void * (*ptr)(size_t, size_t);
ptr = calloc;
...
int *p = (int *) ptr(2, 8);
