#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    int a[42] = {};
    int n;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        a[n % 42]++;
    }
    int cnt = 0;

    for (int i = 0; i < 42; i++)
    {
        if (a[i] > 0)
            cnt++;
    }

    cout << cnt;

    

}