#include <vector>
#include <iostream>
#include <stdexcept>

template<typename T>
class Heap {
private:
    std::vector<T> xs;
    size_t N;

    size_t parent(int i) { return i/2; }
    size_t left(int i) { return 2*i; }
    size_t right(int i) { return 2*i + 1; }

public:
    Heap() : xs(1), N(0) {}

    size_t size() const { return N; }

    void insert(int x)
    {
        if (N + 1 == xs.size())
            xs.push_back(x);
        else
            xs[N + 1] = x;

        int i = N + 1, p = parent(i);

        while (p and xs[p] < xs[i])
        {
            std::swap(xs[p], xs[i]);
            i = p;
            p = parent(i);
        }

        ++N;
    }

    bool empty() const { return N == 0; } 

    T max() const 
    {
        if (empty())
            throw std::out_of_range("Empty heap");

        return xs[1];
    }

    T extract_max()
    {
        if (empty())
            throw std::out_of_range("Empty heap");

        std::swap(xs[1], xs[N]);
        auto x = xs[1];
        --N;

        int i = 1, n = left(i) > N ? 0 : left(i);

        while (n)
        {
            auto r = right(i) > N ? 0 : right(i);

            if (r and xs[r] > xs[n])
                n = r;

            if (xs[i] < xs[n])
            {
                std::swap(xs[i], xs[n]);
                i = n;
                n = left(i) > N ? 0 : left(i);
            } else
                n = 0;
        }

        return x;
    }

    static Heap heapify(const std::vector<T>& xs)
    {
        Heap<T> h;

        h.xs.push_back(0);
        h.xs.insert(h.xs.begin() + 1, xs.begin(), xs.end());

        h.N = xs.size();

        for (int i = h.N; i >= 1; --i)
        {
            auto p = i;
            auto n = h.left(p) > h.N ? 0 : h.left(p);

            while (n)
            {
                auto r = h.right(p) > h.N ? 0 : h.right(p);

                if (r and h.xs[r] > h.xs[n])
                    n = r;

                if (h.xs[p] < h.xs[n])
                {
                    std::swap(h.xs[p], h.xs[n]);
                    p = n;
                    n = h.left(p) > h.N ? 0 : h.left(p);
                } else
                    n = 0;
            }
        }

        return h;
    }

    friend std::ostream& operator<<(std::ostream& os, const Heap& h)
    {
        for (size_t i = 1; i <= h.N; ++i)
            os << h.xs[i] << (i == h.N ? "" : " ");

        return os;
    }
};

int main()
{
    Heap<int> h;
    std::vector<int> xs { 40, 98, 17, 33, 21, 57, 40, 89, 62, 74 };

    for (const auto& x : xs)
        h.insert(x);

    std::cout << h << '\n';

    h.insert(93);

    std::cout << h << '\n';

    std::cout << "Max = " << h.extract_max() << '\n';
    std::cout << h << '\n';

    auto h2 = Heap<int>::heapify(xs);

    std::cout << h2 << '\n';

    return 0;
}
