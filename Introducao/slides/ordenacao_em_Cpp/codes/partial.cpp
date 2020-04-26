#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using score = pair<int, string>;

void topN(vector<score>& scores, size_t N)
{
    partial_sort(scores.begin(), scores.begin() + N, scores.end(),
        [](const score& a, const score& b) {
            return a.first == b.first ? a.second < b.second :
                a.first > b.first;
        });

    for (size_t i = 0; i < min(N, scores.size()); ++i)
        cout << i + 1 << ". " << scores[i].second << " - "
            << scores[i].first << " pontos\n";
}

int main()
{
    vector<score> scores { score(50, "Alonso"), score(207, "Bottas"),
        score(331, "Hamilton"), score(53, "Hulkenberg"), 
        score(53, "Perez"), score(53, "Magnussen"), 
        score(196, "Raikkonen"), score(146, "Ricardo"),
        score(173, "Verstappen"), score(264, "Vettel") };

    topN(scores, 5);

    for (const auto& [s, name] : scores)
        cout << name << " - " << s << " pontos\n";

    return 0;
}
