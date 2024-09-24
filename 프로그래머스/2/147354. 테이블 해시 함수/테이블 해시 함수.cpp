#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;

	sort(data.begin(), data.end(), [=](const auto& a, const auto& b) {
		if (a[col - 1] == b[col - 1])
			return a[0] > b[0];

		return a[col - 1] < b[col - 1];
		});

	for (int i = row_begin - 1; i <= row_end - 1; i++)
	{
		int temp = 0;
		for (int j = 0; j < data[i].size(); j++)
		{
			int temp2 = data[i][j] % (i + 1);
			temp += temp2;
		}

		answer ^= temp;
	}

	return answer;
}