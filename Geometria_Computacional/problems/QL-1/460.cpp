#include <bits/stdc++.h>

struct Rectangle {
    int Px, Py, Qx, Qy;

    Rectangle intersection(const Rectangle& r) const {
        auto xmin = std::max(Px, r.Px);
        auto xmax = std::min(Qx, r.Qx);

        if (xmin >= xmax)
            return { -1, -1, -1, -1 };

        auto ymin = std::max(Py, r.Py);
        auto ymax = std::min(Qy, r.Qy);

        if (ymin >= ymax)
            return { -1, -1, -1, -1 };

        return { xmin, ymin, xmax, ymax };
    }
};

int main()
{
    int T;
    std::cin >> T;

    for (int test = 0; test < T; ++test)
    {
        int xl, yl, xu, yu;

        std::cin >> xl >> yl >> xu >> yu;
        Rectangle r { xl, yl, xu,yu };

        std::cin >> xl >> yl >> xu >> yu;
        Rectangle s { xl, yl, xu,yu };

        auto ans = r.intersection(s);

        if (test)
            printf("\n");

        if (ans.Px == -1)
            std::cout << "No Overlap\n";
        else
            std::cout << ans.Px << " " << ans.Py << " " 
                << ans.Qx << " " << ans.Qy << '\n';
    }

    return 0;
}
