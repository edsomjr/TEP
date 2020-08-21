vector<int> ns { 2, -1, 5, 8, 3, 10 };

// Primeiro os pares, depois os impares
sort(ns.begin(), ns.end(), [](int x, int y) {
    int a = x % 2;
    int b = y % 2;
    return a == b ? x < y : (a == 0);
});
