#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int t;
    cin >> t;

    while (t--)
    {
        int h, w, n;
        cin >> h >> w >> n;
        int room;
        if (n % h != 0)
        {
            room = n % h * 100 + n / h + 1;
        }
        else
            room = h * 100+n/h;


        cout << room << '\n';
    }

}