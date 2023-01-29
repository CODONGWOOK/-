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
bool visited[101][101]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�
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
                visited[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
                q.push({ i,j }); // ť�� �������� ����.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // �����¿� ĭ�� ���캼 ���̴�.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // ���� ���� ��� �Ѿ
                        if (visited[nx][ny] || board[nx][ny] != 'R') continue; // �̹� �湮�� ĭ�̰ų� Ž�� ������ ĭ�� �ƴ� ���
                        visited[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
                        q.push({ nx,ny });
                    }
                }
                cnt1++;
            }
            if (board[i][j] == 'G' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
                q.push({ i,j }); // ť�� �������� ����.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // �����¿� ĭ�� ���캼 ���̴�.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // ���� ���� ��� �Ѿ
                        if (visited[nx][ny] || board[nx][ny] != 'G') continue; // �̹� �湮�� ĭ�̰ų� Ž�� ������ ĭ�� �ƴ� ���
                        visited[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
                        q.push({ nx,ny });
                    }
                }
                cnt1++;
            }
            if (board[i][j] == 'B' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
                q.push({ i,j }); // ť�� �������� ����.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // �����¿� ĭ�� ���캼 ���̴�.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // ���� ���� ��� �Ѿ
                        if (visited[nx][ny] || board[nx][ny] != 'B') continue; // �̹� �湮�� ĭ�̰ų� Ž�� ������ ĭ�� �ƴ� ���
                        visited[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
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
                visited[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
                q.push({ i,j }); // ť�� �������� ����.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // �����¿� ĭ�� ���캼 ���̴�.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // ���� ���� ��� �Ѿ
                        if (visited[nx][ny] || board[nx][ny] =='B') continue; // �̹� �湮�� ĭ�̰ų� Ž�� ������ ĭ�� �ƴ� ���
                        visited[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
                        q.push({ nx,ny });
                    }
                }
                cnt2++;
            }

            if (board[i][j] == 'B' && !visited[i][j])
            {
                visited[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
                q.push({ i,j }); // ť�� �������� ����.

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    { // �����¿� ĭ�� ���캼 ���̴�.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // ���� ���� ��� �Ѿ
                        if (visited[nx][ny] || board[nx][ny] != 'B') continue; // �̹� �湮�� ĭ�̰ų� Ž�� ������ ĭ�� �ƴ� ���
                        visited[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
                        q.push({ nx,ny });
                    }
                }
                cnt2++;
            }

        }
    }

    cout << cnt1<<' '<<cnt2;
}