 vector<int> a { 1, 2, 3, 4 };
 auto it = find(a.begin(), a.end(), 2);
 // it será um iterador para o elemento
 auto bit = binary_search(a.begin(), a.end(), 2);
 // bit é um iterador para o elemento encontrado com complexidade
 // O(log n) pois é resultado de uma busca binária
