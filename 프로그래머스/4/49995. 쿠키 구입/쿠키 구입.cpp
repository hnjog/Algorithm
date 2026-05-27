#include <vector>
#include<math.h>

using namespace std;

int solution(vector<int> cookie) {
	const int cSize = cookie.size();
	int answer = 0;
	vector<int> sums(cSize + 1, 0);
	for (int i = 1; i <= cSize; i++)
	{
		sums[i] = sums[i - 1] + cookie[i - 1];
	}

	for (int i = 0; i < cSize; i++)
	{
		int left = i;
		int right = i + 1;
		while (left >= 0 && right < cSize)
		{
			int leftSum = sums[i + 1] - sums[left];
			int rightSum = sums[right + 1] - sums[i + 1];

			if (leftSum == rightSum)
			{
				answer = max(answer, leftSum);
			}

			if (leftSum <= rightSum)
			{
				left--;
			}
			else
			{
				right++;
			}
		}
	}

	return answer;
}