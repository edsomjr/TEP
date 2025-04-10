#include <bits/stdc++.h>

using namespace std;

struct Event { int a, b, i; };

vector<int> solve(int N, const vector<Event>& events)
{
    vector<Event> es(events);

    // Ordena os eventos pelo encerramento
    sort(es.begin(), es.end(), [](const Event& x, const Event& y) {
        return x.b < y.b;
    });

    vector<int> ans(1, es[0].i);
    int last = es[0].b;

    for (int i = 1; i < N; ++i)
    {
        // O próximo evento começa antes do término do anterior
        if (es[i].a < last)
            continue; 

        ans.emplace_back(es[i].i);
        last = es[i].b;
    }

    // Retorna os identificadores dos eventos escolhidos
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Event> es(N);

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;

        es[i] = Event { a, b, i + 1 };
    }

    auto ans = solve(N, es);

    cout << "\n" << ans.size() << '\n';

    for (auto i : ans)
        cout << es[i - 1].a << ' ' << es[i - 1].b << '\n';

    return 0;
}
