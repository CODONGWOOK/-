#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        bool check = true;
        if (a == 0 && b == 0 && c == 0)
            break;
        
        if (a > b&&a>c)
        {
            if ((b * b + c * c) != a * a)
                check = false;                
        }
        if (b > a && b > c)
        {
            if ((a * a + c * c) != b * b)
                check = false;
        }
        if (c > a && c > b)
        {
            if ((a * a + b * b) != c * c)
                check = false;
        }


        if (check)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';

    }

}