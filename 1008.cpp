#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int A, B;
  cin >> A >> B;
  cout << fixed;     // 고정 소수점
  cout.precision(9); // 유효 숫자 (위의 고정소수점으로 인해 소수점이하부터 카운트)
  cout << (double)A / (double)B;
  cout.unsetf(ios::fixed); // 고정 소수점 해제
}