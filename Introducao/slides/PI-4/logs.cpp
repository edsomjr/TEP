#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))

#define LOGM(msg) (cerr << (msg))

#define LOGV(vec, sep) {                                        \\
    cerr << #vec << " =";                                       \\
    for (const auto& v : (vec)) cerr << " " << v;               \\
    cerr << (sep); }

#define LOGA(arr, N, sep) {                                     \\
        cerr << #arr << " =";                                   \\
        for (int i = 0; i < N; ++i) cerr << " " << (arr)[i];    \\
        cerr << (sep); }

#define LOGA2(arr, N, M, sep) {                                 \\
        cerr << #arr << " =\n";                                 \\
        for (int i = 0; i < N; ++i) {                           \\
            for (int j = 0; j < M; ++j)                         \\
                cerr << (arr)[i][j] << " ";                     \\
            cerr << endl;                                       \\
        } cerr << (sep); }
