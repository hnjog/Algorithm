#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int GetNear(const vector<int>& talls, vector<bool>& visit, int b, int nowIdx, int nowVal)
{
	if (nowVal >= b)
	{
		return nowVal - b;
	}

	int ret = INT_MAX;

	for (int i = nowIdx ; i < talls.size(); i++)
	{
		if (visit[i])
			continue;

		visit[i] = true;
		ret = min(ret, GetNear(talls,visit, b, i, nowVal + talls[i]));
		visit[i] = false;
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		int n, b;
		cin >> n >> b;

		vector<int> talls(n);
		vector<bool> visit(n,false);
		for (int i = 0; i < n; i++)
			cin >> talls[i];

		cout << '#' << test_case << ' ' << GetNear(talls, visit, b, 0, 0) << '\n';
	}
	return 0;
}