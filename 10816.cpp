#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	
	map<int, int> card;
	for (int i = 0; i < n; i++)
	{
		int key;
		cin >> key;
		card[key]++;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int search;
		cin >> search;
		cout << card[search] << ' ';
	}

}
/*


*/
