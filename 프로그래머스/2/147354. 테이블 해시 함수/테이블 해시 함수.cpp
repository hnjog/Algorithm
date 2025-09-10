#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;

	col--;
	row_begin--;
	row_end--;

	sort(data.begin(), data.end(), [=]
	(const vector<int>& a, const vector<int>& b)
		{
			if (a[col] == b[col])
				return a[0] > b[0];

			return a[col] < b[col];
		});

	vector<int> values;

	for (int i = row_begin; i <= row_end; i++)
	{
		int sum = 0;
		for (int j = 0; j < data[0].size(); j++)
		{
			sum += data[i][j] % (i+1);
		}

		values.push_back(sum);
	}

	answer = values[0];

	for (int i = 1; i < values.size(); i++)
		answer ^= values[i];

	return answer;
}