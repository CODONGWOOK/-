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
    stack<pair<int,int>>st; //높이, 순서
    st.push({ 100000001,0 }); //stack underflow 방지
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;
        while (st.top().X < h)
            st.pop();
        cout << st.top().Y << ' ';
        st.push({ h,i });
    }
    
}
/*
6 9 5 7 4

6,9 -> 없음. / 5,7 -> 2번째 탑(9) /  4-> 4번째 탑(7)

st.top()의 높이가 h보다 작으면 계속 pop
수신하는 타워의 순서 출력
st에 높이와 순서를 push해준다.



*/