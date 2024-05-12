#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 한 글자만 다른지 확인하는 함수
bool canTransform(const string& from, const string& to)
{
	int diff = 0;
	for (int i = 0; i < from.size(); ++i)
	{
		if (from[i] != to[i])
		{
			++diff;
		}
	}
	return diff == 1;
}

int solution(string begin, string target, vector<string> words)
{
	// 목표 단어가 words 내부에 없다면 0 반환
	if (find(words.begin(), words.end(), target) == words.end())
		return 0;

	queue<pair<string, int>> q;
	vector<bool> visited(words.size(), false); // 방문 여부를 추적

	q.push({ begin, 0 });

	while (!q.empty())
	{
		string current = q.front().first;
		int steps = q.front().second;
		q.pop();

		if (current == target)
			return steps;

		// 모든 words를 순회하며 한 글자만 다른 단어를 찾기
		for (int i = 0; i < words.size(); ++i)
		{
			if (visited[i] == false &&
				canTransform(current, words[i]) == true)
			{
				visited[i] = true;
				q.push({ words[i], steps + 1 });
			}
		}
	}

	// 변환할 수 없는 경우
	return 0;
}