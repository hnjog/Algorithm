#include<iostream>
#include<vector>
#include<string>

using namespace std;

const char cv[2] = { 'm','o' };

void isM(vector<int>& sizes, int step, int n)
{
	if (step == 0)
	{
		if (n == 0)
			cout << cv[0];
		else
			cout << cv[1];

		return;
	}

	int nowC = sizes[step - 1];
	if (nowC > n)
	{
		isM(sizes, step - 1, n);
		return;
	}

	n -= nowC;

	int nowMooSize = 3 + step;
	if (nowMooSize > n)
	{
		if (n == 0)
			cout << cv[0];
		else
			cout << cv[1];

		return;
	}

	n -= nowMooSize;

	isM(sizes, step - 1, n);
}

int main()
{
	int n;
	cin >> n;
	n--;

	if (n < 3)
	{
		if (n == 0)
			cout << cv[0];
		else
			cout << cv[1];

		return 0;
	}

	vector<int> sizes;
	sizes.push_back(3);

	int startIdx = 1;

	while (true)
	{
		int nowSize = sizes[startIdx - 1] * 2 + 3 + startIdx;
		sizes.push_back(nowSize);

		if (nowSize > n)
			break;

		startIdx++;
	}


	isM(sizes, startIdx, n);

	return 0;
}