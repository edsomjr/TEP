/**
 * Implementação do algoritimo anagram_position.cpp.
 * Dado uma string o mesmo retorna a posição que esta string se encontra dentre todas as suas permutações (não repetidas.).
 *
 * Autor: Iago Rocha 
 * Data: 12/07/2022
 * Licença: LGPL. Sem copyright.
 */
#include <bits/stdc++.h>
#define MAX 250
using namespace std;
using ll = long long;
using ull = unsigned long long;

// Fatorial usando progamação dinâmica. O(N).
vector <ull> fatAns(MAX, 0); 
ull fastFat(int n){
    if(fatAns[n]) return fatAns[n];
    fatAns[n] = n * fastFat(n-1);
    return fatAns[n];

}

// Calcular o total de combinações sem repetições.
ull totalPermutations(string s){
    ull ans = 1;
    map <char, int> h; // Histograma para dividir pelo fatorial dos repetidos.
    for(int i = 0; i < s.size(); ++i){
        ans *= (i+1);
        h[s[i]] ++;
    }

    for(auto i : h) ans /= fastFat(i.second);        

    return ans;
}

// Dado a string, retorna a posição da mesma dentre todas as permutações.
ull anagramPosition(string s){
    // 'sorted s' o primeiro anagrama.
    string ss = s;
    sort(ss.begin(), ss.end());

    ull ans = 0;
    ull p = 0;
    // Remover da string original até que forme a desejada.
    while(!ss.empty()){
        unsigned int i = 0;
        while(i < ss.size()){
            if(ss[i] == s[p]){
                // cout << ss[i] << " YES." << endl;
                break;
            } 
            else {
                string tempstr = ss;
                tempstr.erase(tempstr.begin() + i);
                ans += totalPermutations(tempstr);
                // cout << ss[i] << " NO. Sum : " << totalPermutations(tempstr) << endl;
                char temp = ss[i];
                while(ss[i] == temp) i++;
            }
        }
        ss.erase(ss.begin()+i);
        p++;
    }
    return ans;
}

// Mostrar todas as permutações possíveis, simplesmente para provar o resultado.
void showEveryAnagram(string s){
    sort(s.begin(), s.end());
    map<string,bool> check;
    ull i = 0;
    do{
        if(!check[s]) cout << i << " " <<  s << endl , ++i;

    }
    while(next_permutation(s.begin(), s.end()));
}

int main(){
    string s;
    cin >> s;
    showEveryAnagram(s);
    cout << anagramPosition(s) << endl;
    return 0;
}
