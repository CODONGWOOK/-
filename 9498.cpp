#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();
    
    int score;
    cin >> score;
    int grade = score / 10;
    switch (grade)
    {
        case 10: cout << 'A'; break;
        case 9: cout << 'A'; break;
        case 8: cout << 'B'; break;
        case 7: cout << 'C'; break;
        case 6: cout << 'D'; break;
        default:
            cout << 'F'; break;
    }
}