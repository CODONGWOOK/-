#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int h, m;
    cin >> h >> m;
    m -= 45;
    if (m < 0)
    {
        h--;
        m += 60;
        if (h < 0)
            h += 24;
    }

    cout << h << ' ' << m;
}