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
int d[107][107]; //�ִ� �Ÿ� ���̺�
int nxt[107][107]; //��� ���� ���̺�
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
        nxt[a][b] = b; //�ٸ� ������ ��ġ�� �ʴ� ��� ǥ��
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
                    d[i][j] = d[i][k] + d[k][j]; //��� ����
                    nxt[i][j] = nxt[i][k]; //�� ȿ������ ��ΰ� �ִٸ� �ִܰŸ� ���̺� ����
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
            int st = i; //���� ����
            while (st != j)
            {
                path.push_back(st); //��� �����
                st = nxt[st][j]; //���� ����
            }
            path.push_back(j); //���� ����
            cout << path.size() << ' '; //������ ���� ���
            for (auto x : path)
                cout << x << ' '; //��� ���
            cout << '\n';
        }
    }
}
/*
���� ����: a ���� ����: b ���:c
����-> ����
*/

