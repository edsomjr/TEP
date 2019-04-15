#include <bits/stdc++.h>

bool solve(int N, const std::vector<std::string>& words)
{
    auto c = words[0].back();

    std::set<std::string> S;
    S.insert(words[0]);

    for (int i = 1; i < N; ++i)
    {
        if (S.count(words[i]) or words[i].front() != c)
            return false;

        c = words[i].back();
        S.insert(words[i]);
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<std::string> words(N);

    for (int i = 0; i < N; ++i)
        std::cin >> words[i];

    auto ans = solve(N, words);

    std::cout << (ans ? "Yes\n" : "No\n");

    return 0;
}
