#ifndef PLUGIN_H
#define PLUGIN_H

typedef struct _Plugin {
    void *handle;
    const char * (*symbol) ();
    int (*operation) (int, int);
} Plugin;

extern Plugin * load(const char *path);
extern void release(Plugin *plugin);

#endif
