#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    int a, b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}