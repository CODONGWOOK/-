#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second
int board[51][51]; 
bool visited[51][51]; // 해당 칸을 방문했는지 여부를 저장
int n, m, k; // n = 행의 수, m = 열의 수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int main(void) {
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        while (k--)
        {
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }
        int cnt = 0;
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1&&visited[i][j]!=1)
                {
                    visited[i][j] = 1; // (i, j)을 방문했다고 명시
                    Q.push({ i,j }); // 큐에 시작점을 삽입.

                    while (!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        { // 상하좌우 칸을 살펴볼 것이다.
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                            if (visited[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 탐색 가능한 칸이 아닐 경우
                            visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                            Q.push({ nx,ny });
                        }
                    }
                    cnt++;
                }

            }
        }
        
        cout << cnt << '\n';
        for (int i = 0; i < 51; i++)
        {
            fill(board[i], board[i] + 51, 0);
            fill(visited[i], visited[i] + 51, 0);
        }

    }
}