for (i = 0, length = 1; i < n - 1; i++) {
    for (i1 = k = i, i2 = i + 1; k < n - 1 && a[k] < a[k+1]; k++, i2++)
         if (length < i2 - i1 + 1)
            length = i2 - i1 + 1;
}
