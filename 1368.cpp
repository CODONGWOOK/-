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


vector<int> p(10001, -1);

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}
bool group(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)return true;
    if (p[u] == p[v])
        p[u]--;
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return false;
}
tuple<int, int, int>edge[100007];
//��� ����1 ����2
int main()
{
    fastio();

    int n; int e = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cost;
        cin >> cost;
        edge[e++] = { cost,i,n+1 };
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost;
            cin >> cost;
            if (i == j)
                continue;
            edge[e++] = { cost,i,j };
        }
    }

    sort(edge, edge + e); //ù ��° ������ ����� �������� ����
    int cnt = 0;
    int res = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (group(a, b)) continue;
        res += cost;
        cnt++;
        if (cnt == n) // ������ ������ �ϳ� �߰� �Ǿ����Ƿ� v-1==n��
            break;
    }
    cout << res;
}
/*
*/

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

vector<pair<int, int>>adj[10007];//���,����2

bool chk[10007];
//�ּ� ���� Ʈ���� �����ִ��� üũ

int main()
{
    fastio();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cost;
        cin >> cost;
        adj[i].push_back({ cost,n + 1 });
        adj[n + 1].push_back({ cost,i });
    }
    //���,����1,����2
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost;
            cin >> cost;
            if (i >= j)
                continue;
            adj[i].push_back({ cost,j });
            adj[j].push_back({ cost,i });
        }
    }
    chk[n + 1] = 1;
    for (auto nxt : adj[n + 1])
        pq.push({ nxt.X,n + 1,nxt.Y });
    int cnt = 0;
    int res = 0;
    while (cnt < n) //������ ������ �߰������Ƿ� v�� 1�� �þ v-1==n�� �ȴ�.
    {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b])continue;
        res += cost;
        chk[b] = 1;
        cnt++;
        for (auto nxt : adj[b])
        {
            if (!chk[nxt.Y])
                pq.push({ nxt.X,b,nxt.Y });
        }
    }
    cout << res;
}
/*
�� �칰�� �Ǵ� -> ���� ���
���� ����´� -> ���� ���
�������� ���� ����� ���� ����Ϸ��� ���������� ����
-> ��������� ����������� �ٲ� -> ������ ���� �߰�
*/