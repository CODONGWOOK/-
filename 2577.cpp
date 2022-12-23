#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int A, B, C;
    cin >> A >> B >> C;

    int res = A * B * C;
    int cnt[10] = {};
    while (res != 0)
    {
        int flag = res % 10;
        res /= 10;
        cnt[flag]++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << cnt[i]<<'\n';
    }
}