#include <iostream>

int fibonacci_slow_recursive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_slow_recursive(n - 1) + fibonacci_slow_recursive(n - 2);
}

int fibonacci_fast(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;
    int tmp_previous;

    for (int i = 0; i < n - 1; i++)
    {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current;
}

int main()
{
    //  for (int n = 0; n < 20; ++n)
    //    std::cout << fibonacci_fast(n) << '\n';
    //  return 0;

    for (int n = 0; n < 20; ++n)
        std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
