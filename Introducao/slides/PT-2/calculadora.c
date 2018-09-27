/* calculadora.c
 *
 * Compile com a linha abaixo:
 *
 *  $ gcc -o calculadora calculadora.c plugin.c -I. -ldl
 *
 * Os plugins devem estar no diretório 'plugins'.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "plugin.h" 

Plugin ** load_plugins(const char *directory, int *qtd) {
    DIR *dir = NULL;
    Plugin **plugins;
    struct dirent *entry;
    int size = 0;
    char path[4096];

    dir = opendir(directory);
    
    if (!dir)
        return NULL;
    
    while (entry = readdir(dir))
        size++;
    
    closedir(dir);
    
    plugins = (Plugin **) calloc(size, sizeof(Plugin *));
    
    if (!plugins) {
        fprintf(stderr, "Sem memoria\n");
        return NULL;
    }
    
    *qtd = 0;
    dir = opendir(directory);
    
    if (!dir) return plugins;
    
    while (entry = readdir(dir)) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;
       
        sprintf(path, "%s/%s", directory, entry->d_name);
        plugins[*qtd] = load(path);
        
        if (plugins[*qtd]) {
            (*qtd)++;
            printf("Plugin %s loaded\n", path);
        }
    }
    
    closedir(dir);
    
    return plugins;
}

int main() {
    Plugin **plugins = NULL;
    char symbol[128], line[4096];
    int x, y, qtd = 0, i;
    
    plugins = load_plugins("plugins", &qtd);

    if (!plugins) {
        fprintf(stderr, "Can't load plugins\n");
        return -1;
    }
    
    while (1) {
        printf("Insira a expressao: ");
        fgets(line, 4096, stdin);
        
        if (!strcmp(line, "quit\n"))
            break;
        
        sscanf(line, "%d %s %d", &x, symbol, &y);

        for (i = 0; i < qtd; i++) {    
            if (!strcmp(symbol, plugins[i]->symbol())) {
                printf("%d %s %d = %d\n", x, symbol, 
                    y, plugins[i]->operation(x, y));
                break;
            }
        }
        
        if (i == qtd)
            printf("Operacao nao suportada\n");
    }
    
    for (i = 0; i < qtd; i++) 
        release(plugins[i]);
        
    free(plugins);
    
    return 0;
}
