#include <string>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;

bool sortFunc(vector<int> vec1, vector<int> vec2)
{
	if (vec1[0] == vec2[0])
		return vec1[1] < vec2[1];

	return vec1[0] < vec2[0];
}

int solution(vector<vector<int>> lines) {
	int answer = 0;

	sort(lines.begin(), lines.end(), sortFunc);

	map<int, int> m;

	int size = lines.size();

	for (int i = lines[0][0]; i <= lines[size - 1][1]; i++)
	{
		m.insert(make_pair(i, 0));
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = lines[i][0] + 1; j <= lines[i][1]; j++)
		{
			m[j] += 1;
		}
	}

	for (const auto& a : m)
	{
		if (a.second >= 2)
		{
			answer++;
		}
	}

	return answer;
}