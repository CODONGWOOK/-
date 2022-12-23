#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int year;
    cin >> year;

    if (((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0)
        cout << 1;
    else
        cout << 0;

}