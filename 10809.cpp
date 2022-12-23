#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    string s;
    cin >> s;
    int a[26]={};
    for (int i = 0; i < 26; i++)
        a[i] = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if(a[s[i]-'a']==-1)
           a[s[i] - 'a']=i;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << a[i] << ' ';
    }

}