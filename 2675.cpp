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
        int r;
        cin >> r;

        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            string p;
            for (int j = 0; j < r; j++)
            {
                p += s[i];
            }
            cout << p;
        }
        cout << '\n';
    }
}