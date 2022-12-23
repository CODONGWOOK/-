#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    string s;
    cin >> s;
    int sum = 0;
    int flag = 1;
    for (int j = 0; j < s.size(); j++)
    {
      if (s[j] == 'O')
        sum += flag++;
      else
        flag = 1;
    }
    cout << sum << '\n';
  }
}