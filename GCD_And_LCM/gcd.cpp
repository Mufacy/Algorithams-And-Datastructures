#include <iostream>

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
{
  int remainder = a % b;
  if (remainder > 0)
  {
    return gcd_fast(b, remainder);
  }
  else
    return b;
}

int main()
{
  //user input
  int a, b;
  std::cin >> a >> b;

  std::cout << "Fast: " << gcd_fast(a, b) << std::endl;
  std::cout << "naive: " << gcd_naive(a, b) << std::endl;
  return 0;
}