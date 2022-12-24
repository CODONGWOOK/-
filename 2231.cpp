#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int n;
    cin >> n;
    int m=1;
    while (1)
    {
        int check = m;
        int flag = m;
        if (m > n)
        {
            cout << 0;
            break;
        }

        while (flag != 0)
        {
            check +=  flag%10;
            flag /= 10;
        }
        if (check == n) {
            cout << m;
            break;
        }
        m++;
    }
    


}
//m을 계속 증가시킴->flag=m  flag+=flag%10 flag/=10 