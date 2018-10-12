for (i = 4; i < n; i++) {
    for (j = i - 3, sum = a[i - 4]; j <= i; j++)
        sum += a[j];
    cout << "Soma para a[" << i-4 << "-" << i << "] = " << soma << endl; 
}
