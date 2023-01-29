#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second
char board[101][101]; 
bool visited[101][101]; // 해당 칸을 방문했는지 여부를 저장
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int main(void) 
{
    fastio();


    cin >> n ;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'R' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)을 방문했다고 명시
                q.push({ i,j }); // 큐에 시작점을 삽입.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (visited[nx][ny] || board[nx][ny] != 'R') continue; // 이미 방문한 칸이거나 탐색 가능한 칸이 아닐 경우
                        visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        q.push({ nx,ny });
                    }
                }
                cnt1++;
            }
            if (board[i][j] == 'G' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)을 방문했다고 명시
                q.push({ i,j }); // 큐에 시작점을 삽입.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (visited[nx][ny] || board[nx][ny] != 'G') continue; // 이미 방문한 칸이거나 탐색 가능한 칸이 아닐 경우
                        visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        q.push({ nx,ny });
                    }
                }
                cnt1++;
            }
            if (board[i][j] == 'B' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)을 방문했다고 명시
                q.push({ i,j }); // 큐에 시작점을 삽입.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (visited[nx][ny] || board[nx][ny] != 'B') continue; // 이미 방문한 칸이거나 탐색 가능한 칸이 아닐 경우
                        visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        q.push({ nx,ny });
                    }
                }
                cnt1++;
            }

        }
    }

    for (int i = 0; i < n; i++)
        fill(visited[i], visited[i] + 101, 0);


    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((board[i][j] == 'R'||board[i][j]=='G') && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)을 방문했다고 명시
                q.push({ i,j }); // 큐에 시작점을 삽입.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (visited[nx][ny] || board[nx][ny] =='B') continue; // 이미 방문한 칸이거나 탐색 가능한 칸이 아닐 경우
                        visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        q.push({ nx,ny });
                    }
                }
                cnt2++;
            }

            if (board[i][j] == 'B' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)을 방문했다고 명시
                q.push({ i,j }); // 큐에 시작점을 삽입.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (visited[nx][ny] || board[nx][ny] != 'B') continue; // 이미 방문한 칸이거나 탐색 가능한 칸이 아닐 경우
                        visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        q.push({ nx,ny });
                    }
                }
                cnt2++;
            }

        }
    }

    cout << cnt1<<' '<<cnt2;
}