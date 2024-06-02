#include <string>
#include <vector>
#include<set>

using namespace std;

bool isBannedId(const string& user, const string& ban)
{
	const int uSize = user.size();
	const int bSize = ban.size();
	if (uSize != bSize)
		return false;

	for (int i = 0; i < uSize; i++)
	{
		if (ban[i] == '*')
			continue;

		if (user[i] != ban[i])
		{
			return false;
		}
	}

	return true;
}

void dfs(const vector<string>& user_id, const vector<string>& banned_id, vector<bool>& visited_ban, vector<bool>& visited_user, int count, set<vector<int>>& answer, int bIndex)
{
	const int bSize = banned_id.size();
	const int uSize = user_id.size();

	if (count == bSize)
	{
		vector<int> temp;
		for (int i = 0; i < uSize; i++)
		{
			if (visited_user[i])
				temp.push_back(i);
		}

		answer.insert(temp);
		return;
	}

	for (int i = bIndex; i < bSize; i++)
	{
		if (visited_ban[i] == true)
			continue;

		visited_ban[i] = true;

		for (int j = 0; j < uSize; j++)
		{
			if (visited_user[j] == true)
				continue;

			if (isBannedId(user_id[j], banned_id[i]) == true)
			{
				visited_user[j] = true;
				dfs(user_id, banned_id, visited_ban, visited_user, count + 1, answer, bIndex + 1);
				visited_user[j] = false;
			}
		}

		visited_ban[i] = false;
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {
	vector<bool> visited_ban(banned_id.size(), false);
	vector<bool> visited_user(user_id.size(), false);
	set<vector<int>> s;

	dfs(user_id, banned_id, visited_ban, visited_user, 0, s, 0);

	return s.size();
}
