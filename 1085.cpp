#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    fastio();

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int dx = (w - x)>x?x:(w-x);
    int dy = (h - y)>y?y:(h-y);
    
    if (dx > dy)
    {
        cout << dy;
    }
    else
        cout << dx;

    

}