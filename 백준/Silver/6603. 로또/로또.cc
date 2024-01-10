#include<iostream>
#include<memory.h>

using namespace std;

#define dMAX_LOTTO 6
#define dMAX_COUNT 13

void rec(int start,int count,int size, int* _aiNum,int* _aiAns)
{
	if (count == 6)
	{
		for (int i = 0; i < dMAX_LOTTO; i++)
		{
			cout << _aiAns[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < size; i++)
	{
		_aiAns[count] = _aiNum[i];
		rec(i + 1, count + 1, size, _aiNum, _aiAns);
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int aiNums[dMAX_COUNT] = { 0, };
	int answers[dMAX_LOTTO] = { 0, };	// 그냥 정답용 배열을 생각했으면...

	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			cin >> aiNums[i];
		}

		rec(0,0,n,aiNums,answers);

		memset(aiNums, 0, sizeof(int) * dMAX_COUNT);
		cout << '\n';
	}

	return 0;
}
