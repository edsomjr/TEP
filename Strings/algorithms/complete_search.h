/**
 * Implementação de uma função de busca de substrings através de busca completa.
 *
 * Autor: Edson Alves
 * Data: 09/02/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_COMPLETE_SEARCH_H
#define STRING_COMPLETE_SEARCH_H

#include <string>

using namespace std;

int occurrences(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();

    int occ = 0;    // Número de ocorrências de pat em text

    for (int i = 0; i <= n - m; ++i) 
        occ += (pat == text.substr(i, m) ? 1 : 0);

    return occ;
}

#endif
