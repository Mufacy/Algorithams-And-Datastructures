#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    int pieN;
    if (m <= 3)
        pieN = m;

    if (m > 3)
    {
        if (m % 2 == 0)
        {
            pieN = 2 * m;
        }
        else
        {
            pieN = (4 * m) + 3;
        }
    }

    int remainder = n % pieN;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < remainder - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }
    return current;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << "\n";
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}