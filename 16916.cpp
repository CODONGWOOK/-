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
    vector<int> f(s.size()); //문자열의 사이즈만큼 vector 할당
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j]) //문자가 일치하지 않으면
            j = f[j - 1]; // 이전 문자와 동일한 개수

        if (s[i] == s[j])
            f[i] = ++j; //일치하는 문자의 개수 증가
    }
    return f; //일치하는 문자의 개수를 담은 배열을 return
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