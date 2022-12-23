#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k < x)
            cout << k<<' ';
    }
}