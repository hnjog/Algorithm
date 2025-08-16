#include<iostream>
#include<vector>
#include<string>

using namespace std;

const char cv[2] = { 'm','o' };

// m과 o로 이루어짐
// s0 : moo
// s1 : s0 + moo + o + s0
// s2 : s1 + moo + oo + s1
// s3 : s2 + moo + ooo + s2
// ...
// sN : sN-1 + moo + o * n-1 + sN-1
// 
// 요점
// - n이 속한 단계를 구함
// - 분할 정복을 통하여 n이 어떠한 문자인지 구함
// 
//

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