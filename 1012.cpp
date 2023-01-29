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
bool visited[51][51]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n, m, k; // n = ���� ��, m = ���� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�
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
                    visited[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
                    Q.push({ i,j }); // ť�� �������� ����.

                    while (!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        { // �����¿� ĭ�� ���캼 ���̴�.
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ���� ���� ��� �Ѿ
                            if (visited[nx][ny] || board[nx][ny] != 1) continue; // �̹� �湮�� ĭ�̰ų� Ž�� ������ ĭ�� �ƴ� ���
                            visited[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
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