Matrix operator*(const Matrix& A, const Matrix& B)
{
    int n = A.rows(), m = A.cols(), p = B.cols();
    Matrix C(n, p);

    for (int i = 0; i < n; ++i)
        for (int j = 0; i < p; ++j)
            for (int k = 0; k < m; ++k)
                C[i][j] += (A[i][k] * B[k][j]);

    return C;
}
