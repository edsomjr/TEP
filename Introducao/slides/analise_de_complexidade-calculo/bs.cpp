int lo = 0, mid, hi = n - 1;

while (lo <= hi) {
    mid = lo + (hi - lo)/2;

    if (key < a[mid])
        hi = mid - 1;
    else if (key > a[mid])
        lo = mid + 1;
    else return mid;
}

return -1;
