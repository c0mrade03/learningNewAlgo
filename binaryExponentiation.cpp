#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int mod = 1000000007;
const int N = 1e5 + 10;

double binaryExpRecur(int n, int x)
{
  if (x == 0)
  {
    return 1;
  }
  double res = binaryExpRecur(n, x / 2);
  if (x & 1)
  {
    return n * res * res;
  }
  else
  {
    return res * res;
  }
}

double binaryExpIter(int n, int x)
{
  int tempX = abs(x);
  double ans = 1.0;

  while (tempX)
  {
    if (tempX & 1)
    {
      ans *= n;
    }
    n *= n;
    tempX = tempX >> 1;
  }

  if (x < 0)
  {
    return 1.0 / ans;
  }
  return ans;
}

int main()
{
  int n, x;
  cin >> n >> x;
  cout << binaryExpRecur(n, x) << endl;
  cout << binaryExpIter(n, x) << endl;
}
