for (i = 0; i < n; i++) {
    for (j = 1, sum = a[0]; j <= i; j++)
        sum += a[j];
    cout << "Soma para o subvetor a[0-" << i << "] = " << soma << endl;
}
