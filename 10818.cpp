#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    int n;
    cin >> n;
    int min = 1000000;
    int max = -1000000;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (max < k)
            max = k;
        if (min > k)
            min = k;
    }
    cout << min << ' ' << max;
}