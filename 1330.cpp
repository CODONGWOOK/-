#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int A, B;
  cin >> A >> B;

  if (A == B)
  {
    cout << "==";
  }
  else
  {
    A > B ? cout << ">" : cout << "<";
  }
}