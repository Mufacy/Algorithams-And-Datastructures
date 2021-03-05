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
    if (n <= 1)
        return n;

    long prev_pisano = 0;
    long cur_pisano = 1;
    long Pisano_Leng = 1;
    long tmp;

    for (int i = 0; i < m * m; ++i)
    {
        tmp = cur_pisano;
        cur_pisano = (prev_pisano + cur_pisano) % m;
        prev_pisano = tmp;

        if ((cur_pisano == 1) && (prev_pisano == 0))
        {
            Pisano_Leng = i + 1;
            break;
        }
    }

    int remainder = n % Pisano_Leng;

    long long Fib_previous = 0;
    long long Fib_current = 1;
    long long tmp_previous;

    for (long long i = 0; i < remainder - 1; ++i)
    {
        tmp_previous = Fib_previous;
        Fib_previous = Fib_current;
        Fib_current = (tmp_previous + Fib_current) % m;
    }

    return Fib_current % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}