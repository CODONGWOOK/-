#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool cmp(pair<int,string> a,pair<int,string> b)
{
    return a.first < b.first;
}

int main()
{
    fastio();
    

    int n;
    cin >> n;
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++)
    {
        int x; string y;
        cin >> x >> y;
        v.push_back({ x,y });
    }
    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}
/*

*/
