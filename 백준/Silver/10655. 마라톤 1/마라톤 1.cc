#include<iostream>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int taxiDis(const pair<int, int>& v1,const pair<int, int>& v2)
{
	return abs(v1.first - v2.first) + abs(v1.second - v2.second);
}

int func(const vector<pair<int, int>>& vec,const vector<int>& diss, int removeSpot, int sum)
{
	return sum - diss[removeSpot - 1] - diss[removeSpot] + taxiDis(vec[removeSpot - 1],vec[removeSpot + 1]);
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		vec.push_back({ t1,t2 });
	}

	int sum = 0;
	vector<int> diss;
	for (int i = 0; i < n - 1; i++)
	{
		int dis = taxiDis(vec[i], vec[i + 1]);
		diss.push_back(dis);
		sum += dis;
	}

	int minV = INT_MAX;
	for (int i = 1; i < n - 1; i++)
	{
		minV = min(minV, func(vec, diss, i, sum));
	}

	cout << minV;
	
}