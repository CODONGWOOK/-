#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
  fastio();

  int n;
  cin >> n;
  double sum = 0;
  int max = 0;
  double score[1001] = {};
  for (int i = 0; i < n; i++)
  {
    cin >> score[i];
    if (max < score[i])
      max = score[i];
  }
  for (int i = 0; i < n; i++)
  {
    double new_score = (score[i] / max) * 100;
    sum += new_score;
  }
  cout << fixed;
  cout.precision(2);
  cout << sum / n;
}