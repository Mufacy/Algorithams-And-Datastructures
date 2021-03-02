#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
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

long long lcm_fast(int a, int b)
{
  int LCMGCD = gcd_fast(a, b);
  long long Mul = (long long)a * b;
  if (LCMGCD > 1)
    Mul = Mul / LCMGCD;
  return Mul;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << "Fast: " << lcm_fast(a, b) << std::endl;
  return 0;
}