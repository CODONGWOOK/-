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
    vector<char>res;
    int cnt = 1;
    while (n--)
    {
        int k;
        cin >> k;
        while (cnt <= k)
        {
            st.push(cnt++);
            res.push_back('+');
        }
        if (st.top() != k)
        {
            cout << "NO";
            return 0;
        }
        st.pop();
        res.push_back('-');
    }
    for (auto x : res)
    {
        cout << x << '\n';
    }
    
}
/*
1 2 3 4 5 6 7 8

k -> 4 3 6 8 7 5 2 1

1~k까지 push -> k를 pop 
스택의 top이 k가 아니면?
불가능한 경우이므로 NO 출력

*/