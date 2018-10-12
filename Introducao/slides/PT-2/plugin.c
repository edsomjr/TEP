#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "plugin.h" 

Plugin * load(const char *path)
{
    void *handle = NULL;
    Plugin *plugin = NULL;
    const char * (*symbol)() = NULL;
    int (*operation) (int, int) = NULL;
    
    if (!path)
        return NULL;
    
    handle = dlopen(path, RTLD_LAZY | RTLD_GLOBAL);
    
    if (!handle) {
        fprintf(stderr, "Load plugin error: %s\n", dlerror());
        return NULL;
    }

    operation = dlsym(handle, "operation");
    symbol = dlsym(handle, "symbol");
    
    if (!operation || !symbol) {
        fprintf(stderr, "Load plugin error: %s\n", dlerror());
        dlclose(handle);
        return NULL;
    } 
    
    plugin = (Plugin *) malloc(sizeof(Plugin));

    if (!plugin) {
        dlclose(handle);
        return NULL;
    }
    
    plugin->handle = handle;
    plugin->symbol = symbol;
    plugin->operation = operation;
    return plugin;
}

void release(Plugin *plugin) 
{
    if (!plugin)
        return;
    
    if (plugin->handle)
        dlclose(plugin->handle);
    
    free(plugin);
}
