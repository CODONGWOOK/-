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


const int INF = 0x3f3f3f3f;
int d[107][107]; //최단 거리 테이블
int nxt[107][107]; //경로 복원 테이블
int n, m;

int main()
{
    fastio();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + n + 1, INF);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b; //다른 정점을 거치지 않는 경로 표시
    }
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j]; //비용 갱신
                    nxt[i][j] = nxt[i][k]; //더 효율적인 경로가 있다면 최단거리 테이블 갱신
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == 0 || d[i][j] == INF)
            {
                cout << 0 << '\n';
                continue;
            }
            vector<int>path;
            int st = i; //시작 정점
            while (st != j)
            {
                path.push_back(st); //경로 만들기
                st = nxt[st][j]; //다음 정점
            }
            path.push_back(j); //도착 정점
            cout << path.size() << ' '; //도시의 개수 출력
            for (auto x : path)
                cout << x << ' '; //경로 출력
            cout << '\n';
        }
    }
}
/*
시작 정점: a 도착 정점: b 비용:c
버스-> 간선
*/

