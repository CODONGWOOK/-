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

vector<int> fail(string& s) 
{
    vector<int> f(s.size()); //���ڿ��� �����ŭ vector �Ҵ�
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j]) //���ڰ� ��ġ���� ������
            j = f[j - 1]; // ���� ���ڿ� ������ ����

        if (s[i] == s[j])
            f[i] = ++j; //��ġ�ϴ� ������ ���� ����
    }
    return f; //��ġ�ϴ� ������ ������ ���� �迭�� return
}
int main()
{
    fastio();

    string s, p;
    cin >> s >> p;
    vector<int>f = fail(p);
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j > 0 && s[i] != p[j])
            j = f[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == p.size())
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
/*

*/


#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second

int main()
{
    fastio();

    string s, p;
    cin >> s >> p;
    if (strstr((char*)s.c_str(), (char*)p.c_str()) != NULL)
        cout << 1;
    else
        cout << 0;

}
/*

*/