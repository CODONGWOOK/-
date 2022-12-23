#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int a[8] = { 1,2,3,4,5,6,7,8 };
    int b[8] = { 8,7,6,5,4,3,2,1 };
    int c[8] = {};
    for (int i = 0; i < 8; i++)
    {
        cin >> c[i];
    }
    bool check[3] = { true,true,true };
    for (int i = 0; i < 8; i++)
    {
        if (a[i] != c[i])
        {
            check[0] = false;
        }

        if (b[i] != c[i])
        {
            check[1] = false;
        }
    }

    if (check[0] == true)
    {
        cout << "ascending";
    }
    else if (check[1] == true)
    {
        cout << "descending";
    }
    else
        cout << "mixed";
}