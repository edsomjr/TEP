#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using ii = std::pair<int, int>;

struct Vector
{
    int x, y, idx;
    long double angle;

    Vector(int xv, int yv, int i) 
        : x(xv), y(yv), idx(i), angle(atan2l(y, x)) {}

    bool operator<(const Vector& v) const
    {
        return angle < v.angle;
    }
};

ii solve(std::vector<Vector>& vs, int N)
{
    sort(vs.begin(), vs.end());
    vs.push_back(vs.front());

    long double min_angle = 10.0;
    ii ans;

    for (int i = 0; i < N; ++i) {
        auto angle = vs[i + 1].angle - vs[i].angle;

        if (angle < 0) angle += 2*acosl(-1.0);

        if (angle < min_angle) {
            min_angle = angle;
            ans = ii(vs[i].idx, vs[i+1].idx);
        }
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<Vector> vs;

    for (int i = 1; i <= N; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        vs.push_back(Vector { x, y, i });
    }

    auto ans = solve(vs, N);
    std::cout << ans.first << " " << ans.second << '\n';

    return 0;
}
