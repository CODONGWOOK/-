#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int a[9] = {};
  int idx;
  int max = 0;
  for (int i = 0; i < 9; i++)
  {
    cin >> a[i];
    if (max < a[i])
    {
      max = a[i];
      idx = i;
    }
  }
  cout << max << '\n'
       << idx + 1;
}