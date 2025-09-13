#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> cod(n),lenVec;
	for (int i = 0; i < n; i++)
	{
		cin >> cod[i];
	}

	sort(cod.begin(), cod.end());

	for (int i = 1; i < n; i++)
	{
		lenVec.push_back(cod[i] - cod[i - 1]);
	}

	sort(lenVec.begin(), lenVec.end());

	int fullLen = cod.back() - cod[0];
	for (int i = 0; i < k - 1; i++)
	{
        if (lenVec.empty())
			break;
		fullLen -= lenVec.back();
		lenVec.pop_back();
	}

	cout << fullLen;

	return 0;
}