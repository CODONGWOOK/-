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
    stack<pair<int,int>>st; //����, ����
    st.push({ 100000001,0 }); //stack underflow ����
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

6,9 -> ����. / 5,7 -> 2��° ž(9) /  4-> 4��° ž(7)

st.top()�� ���̰� h���� ������ ��� pop
�����ϴ� Ÿ���� ���� ���
st�� ���̿� ������ push���ش�.



*/