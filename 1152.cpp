#include <iostream>
#include <string>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  string s;
  getline(cin, s);
  int count = 0;
  if (s[0] != ' ')
    count++;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != ' ' && s[i - 1] == ' ')
      count++;
  }
  cout << count;
}