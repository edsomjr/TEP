#include <bits/stdc++.h>

using namespace std;

class BITree {
private:
    vector<int> ts;
    size_t N;

    int LSB(int n) { return n & (-n); }

    int RSQ(int i)
    {
        int sum = 0;

        while (i >= 1)
        {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

public:
    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    int RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

    void add(size_t i, int x)
    {
        if (i == 0)
            return;

        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

struct Point {
    int x, y;
};

struct Interval {
    Point A, B;
};

int index(const vector<int>& hs, int value)
{
    auto it = lower_bound(hs.begin(), hs.end(), value);

    return it - hs.begin() + 1;     // Contagem inicia em 1
}

int intersections(const vector<Interval>& is)
{
    struct Event {
        int type, x;
        size_t idx;

        bool operator<(const Event& e) const
        {
            if (x != e.x)
                return x < e.x;

            if (type != e.type)
                return type < e.type;

            return idx < e.idx;
        }
    };

    vector<Event> es;
    set<int> ys;        // Conjunto para compressão das coordenadas

    for (size_t i = 0; i < is.size(); ++i)
    {
        auto I = is[i];

        ys.insert(I.A.y);
        ys.insert(I.B.y);

        auto xmin = min(I.A.x, I.B.x);
        auto xmax = max(I.A.x, I.B.x);

        if (I.A.x == I.B.x)     // Vertical
            es.push_back( { 2, xmin, i });
        else                    // Horizontal
        {
            es.push_back( { 1, xmin, i });
            es.push_back( { 3, xmax, i });
        }
    }

    sort(es.begin(), es.end());

    vector<int> hs(ys.begin(), ys.end());   // Mapa de compressão
    BITree ft(hs.size());
    auto total = 0;

    for (const auto& event : es)
    {
        auto I = is[event.idx];

        switch (event.type) {
        case 1:
            {
                auto y = index(hs, I.A.y);
                ft.add(y, 1);
            }
            break;

        case 2:
            {
                auto ymin = min(index(hs, I.A.y), index(hs, I.B.y));
                auto ymax = max(index(hs, I.A.y), index(hs, I.B.y));

                total += ft.RSQ(ymin, ymax);
            }
            break;

        default:
            {
                auto y = index(hs, I.B.y);
                ft.add(y, -1);
            }
        }
    }

    return total;
}

int main()
{
    vector<Interval> is { 
        { Point { 2, 6 }, Point { 5, 6 } },
        { Point { 1, 5 }, Point { 6, 5 } },
        { Point { 5, 4 }, Point { 8, 4 } },
        { Point { 3, 3 }, Point { 7, 3 } },
        { Point { 5, 2 }, Point { 8, 2 } },
        { Point { 1, 1 }, Point { 4, 1 } },
        { Point { 4, 7 }, Point { 4, 2 } },
        { Point { 2, 3 }, Point { 2, 0 } },
        { Point { 6, 3 }, Point { 6, 1 } },
    };

    auto ans = intersections(is);

    cout << ans << '\n';

    return 0;
}
