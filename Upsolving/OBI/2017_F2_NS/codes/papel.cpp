#include <bits/stdc++.h>

#ifdef DEBUG
#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))

#define LOGM(msg) (cerr << (msg))

#define LOGV(vec, sep) {                                        \
    cerr << #vec << " =";                                       \
    for (const auto& v : (vec)) cerr << " " << v;               \
    cerr << (sep); }

#define LOGD(dict, sep) {                                       \
    cerr << #dict << " =\n";                                    \
    for (const auto& [k, v] : (dict))                           \
        cerr << k << " -> " << v << '\n';                       \
    cerr << (sep); }

#define LOGA(arr, N, sep) {                                     \
        cerr << #arr << " =";                                   \
        for (int i = 0; i < N; ++i) cerr << " " << (arr)[i];    \
        cerr << (sep); }

#define LOGA2(arr, N, M, sep) {                                 \
        cerr << #arr << " =\n";                                 \
        for (int i = 0; i < N; ++i) {                           \
            for (int j = 0; j < M; ++j)                         \
                cerr << (arr)[i][j] << " ";                     \
            cerr << endl;                                       \
        } cerr << (sep); }
#else
#define LOG(var, sep)
#define LOGM(msg)
#define LOGV(vec, sep)
#define LOGA(arr, N, sep)
#define LOGA2(arr, N, M, sep)
#endif

using namespace std;
using ll = long long;
using ii = pair<int, int>;

using namespace std;

int solve(int N, vector<int>& hs)
{
    LOGV(hs, endl);
    LOG(N, endl);
    // Compressão dos adjacentes iguais
    auto it = unique(hs.begin(), hs.end());

    N = (int) distance(hs.begin(), it);
    hs.resize(N);

    // Identificação dos vales e picos
    vector<int> cs;
 
    for (int i = 1; i <= N - 2; ++i)
        if ((hs[i - 1] < hs[i] and hs[i] > hs[i + 1]) ||
            (hs[i - 1] > hs[i] and hs[i] < hs[i + 1]))
                cs.push_back(hs[i]);

    // Finaliza com um vale
    if (cs.size() % 2) 
        cs.push_back(0);

    // Geração dos eventos para o sweep line
    vector<ii> es;
    int OPEN = 1, CLOSE = -1;

    for (size_t i = 0; i < cs.size(); i += 2)
    {
        es.push_back(ii(cs[i + 1], OPEN));
        es.push_back(ii(cs[i], CLOSE));
    }

    sort(es.begin(), es.end());

    int ans = 1, open = 0;

    for (auto e : es)
    {
        auto t = e.second;

        open += t;
        ans = max(ans, open);
    }

    return ans + 1;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> hs(N + 2, 0);

    for (int i = 1; i <= N; ++i)
        cin >> hs[i];

    auto ans = solve(N, hs);

    cout << ans << '\n';

    return 0;
}
