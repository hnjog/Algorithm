#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int recur(vector<vector<int>>& vec, int n, int startY, int startX)
{
	if (n == 1)
	{
		return vec[startY][startX];
	}

	vector<int> p;
	p.push_back(recur(vec, n / 2, startY, startX));
	p.push_back(recur(vec, n / 2, startY + n / 2, startX));
	p.push_back(recur(vec, n / 2, startY, startX + n / 2));
	p.push_back(recur(vec, n / 2, startY + n / 2, startX + n / 2));

	sort(p.begin(), p.end());
	
	return p[2];
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> vec[i][j];

	cout << recur(vec, n, 0, 0);

}