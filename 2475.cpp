#include <iostream>
#include <string>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int n;
  int sum = 0;
  for (int i = 0; i < 5; i++)
  {
    cin >> n;
    sum += n * n;
  }
  cout << sum % 10;
}