#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int n;
    cin >> n;
    int a = 1;
    for (int i = 0; i < n; i++)
    {
        cout << a++ << '\n';
    }
}