#include <iostream>
#include <string>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int a[26] = {};
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    s[i] = toupper(s[i]);
    a[s[i] - 'A']++;
  }
  int max = 0;
  int idx = 0;
  for (int i = 0; i < 26; i++)
  {
    if (max < a[i])
    {
      max = a[i];
      idx = i;
    }
  }
  int flag = 0;
  for (int i = 0; i < 26; i++)
  {
    if (max == a[i])
      flag++;
  }
  if (flag > 1)
    cout << '?';
  else
    cout << (char)(idx + 'A');
}