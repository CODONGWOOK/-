#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second


int main()
{
    fastio();

    int n;
    cin >> n;
    stack<int>st; 
    long long cnt = 0;
    while (n--)
    {
        int h;
        cin >> h;
        while (!st.empty() && st.top() <= h)
        {
            st.pop();
        }
        cnt += st.size();
        st.push(h);
    }
    cout << cnt;
}
/*
10  3   7   4  12   2
3 + 0 + 1 + 0 + 1 + 0 = 5
높거나 같으면 못봄 -> 낮아야만 볼 수 있음.

10   +0
10 3 +1
10 7 +1
10 7 4 +2
12 +0
12 2  +1

0+1+1+2+0+1 = 5
*/