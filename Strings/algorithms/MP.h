/**
 * Implementação do algoritmo de Morris-Pratt e suas funções associadas.
 *
 * Autor: Edson Alves
 * Data: 09/02/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_MP_H
#define STRING_MP_H

#include <string>
#include <vector>

using namespace std;

// Computa o tamanho das bordas de pat: bord[j] é o tamanho da borda da
// substring pat[1..(j-1)]
//
// Complexidade: O(m)
vector<int>
borders1(const string& pat)
{
    int m = pat.size();
    int i = 1, j = 0;

    vector<int> bord(m + 1, 0);    // Inicialmente, bord[j] = 0 para todo j
    bord[0] = -1;

    while (i < m + 1)
    {
        while (i + j < m and pat[j] == pat[i + j])
        {
            ++j;

            bord[i + j] = max(bord[i + j], j);
        }

        i += j - bord[j]; 
        j = max(0, bord[j]);
    } 

    return bord;
}

// Computa o tamanho das bordas de pat: bord[j] é o tamanho da borda da
// substring pat[0..(j-1)]
//
// Complexidade: O(m)
vector<int> borders2(const string& pat)
{
    int m = pat.size();
    int t = -1;

    vector<int> bord(m + 1);
    bord[0] = -1;

    for (int j = 1; j <= m; ++j)
    {
        while (t >= 0 and pat[t] != pat[j - 1])
            t = bord[t];

        ++t;
        bord[j] = t;
    }

    return bord;
}

// Implementação do algoritmo de MP, usando borders1
//
// Complexidade: O(n + m)
int MP1(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bords = borders1(pat);

    while (i <= n - m)
    {
        while (j < m and pat[j] == text[i + j])
            ++j;

        if (j == m)
            ++occ;

        int MP_shift = j - bords[j];

        i += MP_shift;
        j = max(0, j - MP_shift);
    } 

    return occ;
}

// Implementação do algoritmo de MP, usando borders2
//
// Complexidade: O(n + m)
int MP2(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bords = borders2(pat);

    while (i <= n - m)
    {
        while (j < m and pat[j] == text[i + j])
            ++j;

        if (j == m)
            ++occ;

        int MP_shift = j - bords[j];

        i += MP_shift;
        j = max(0, j - MP_shift);
    } 

    return occ;
}


#endif
