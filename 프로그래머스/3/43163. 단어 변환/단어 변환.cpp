#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool IsOneDiffer(const string& a, const string& b)
{
	if (a.size() != b.size())
		return false;

	int differCount = 0;

	int ss = a.size();

	for (int i = 0; i < ss; i++)
	{
		if (a[i] != b[i])
		{
			differCount++;
		}

		if (differCount > 1)
			break;
	}

	if (differCount != 1)
		return false;

	return true;
}

void dfs(const string& now, const string& target, const vector<string>& words, unordered_set<string>& us, int nowC, int& answer)
{
	if (now == target)
	{
		if (answer == 0 ||
			answer > nowC)
		{
			answer = nowC;
		}

		return;
	}

	us.insert(now);

	for (const string& str : words)
	{
		if (us.find(str) != us.end())
			continue;

		if (IsOneDiffer(now, str) == true)
		{
			dfs(str, target, words, us, nowC + 1, answer);
		}
	}

	us.erase(now);
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	unordered_set<string> us;
	us.reserve(words.size());
	dfs(begin, target, words, us, 0, answer);
	return answer;
}