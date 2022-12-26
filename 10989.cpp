#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int cnt[10001];
int main()
{
    fastio();
    
    int n; 
    cin >> n;

    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        cnt[k]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            cout << i<<'\n';
        }
    }


}
/*

*/
