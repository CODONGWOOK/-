#include <iostream>
#include <string>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    string a, b;
    cin >> a >> b;

    string tmp1, tmp2;
    for (int i = 2; i >=0; i--)
    {
        tmp1 += a[i];
        tmp2 += b[i];
    }
    stoi(tmp1) > stoi(tmp2) ? cout << tmp1 :cout<<tmp2;


}