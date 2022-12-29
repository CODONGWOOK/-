#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();

	int n;
	cin >> n; //nÀº È¦¼ö

	vector<int>v(n, 0);
	double sum = 0;
	int freq[8001]={}; 
	int max_freq = 0;
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];

		freq[v[i] + 4000]++;
		if (freq[v[i] + 4000] > max_freq) 
			max_freq = freq[v[i] + 4000]; 
	}
	int max_freq_value = -1;
	for (int i = 0; i < 8001; i++)
	{

		if (check==true&&max_freq == freq[i])
		{
			max_freq_value = i - 4000;
			break;
		}

		if (max_freq == freq[i])
		{
			max_freq_value = i - 4000;
			check = true;
		}
			
	}

	sort(v.begin(), v.end());
	int avg = (round)(sum / n);
	int mid = v[n / 2];
	int range = v[v.size() - 1] - v[0];
	cout << avg << '\n';
	cout << mid << '\n';
	cout << max_freq_value << '\n';
	cout << range << '\n';

	
}


/*
 
*/
