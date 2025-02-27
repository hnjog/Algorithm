#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

void bfs(vector<string>& storage, char c, map<char, set<pii>>& side,vector<pii>& temp)
{
	queue<pii> q;
	for (const pii& p : side[c])
	{
		q.push(p);
	}

	int h = storage.size();
	int w = storage[0].size();
	set<pii> visited;

	while (q.empty() == false)
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (i < 0 || i >= h ||
			j < 0 || j >= w)
			continue;

		if (visited.find({ i,j }) != visited.end())
			continue;

		visited.insert({ i,j });
		
		if (storage[i][j] == c)
		{
			storage[i][j] = ' ';
			for (int v = 0; v < 4; v++)
			{
				int ni = i + dirY[v];
				int nj = j + dirX[v];

				q.push({ ni,nj });
			}
		}
		else
		{
			temp.push_back({ i,j });
		}
	}
}

int solution(vector<string> storage, vector<string> requests) {
	map<char, set<pii>> side, full;

	int height = storage.size();
	int width = storage[0].size();
	int answer = height * width;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			char c = storage[i][j];

			full[c].insert({ i,j });

			if (i == 0 || j == 0 ||
				i == height - 1 || j == width - 1)
			{
				side[c].insert({ i,j });
			}
		}
	}

	for (string req : requests)
	{
		char c = req[0];
		vector<pii> temp;

		if (req.size() == 2)
		{
			answer -= full[c].size();

			for (auto& p : full[c])
			{
				storage[p.first][p.second] = ' ';
			}

			full.erase(c);

			for (auto& p : side[c])
			{
				side[' '].insert(p);
			}
		}
		else
		{
			answer -= side[c].size();
			for (auto& p : side[c])
			{
				int i = p.first;
				int j = p.second;

				if (full[c].find({ i,j }) != full[c].end())
					full[c].erase({ i,j });

				storage[i][j] = ' ';
				side[' '].insert(p);
			}
		}

		side.erase(c);

		// 외곽쪽 빈칸을 기준으로 다시 side에 요소 채워넣기
		bfs(storage, ' ', side, temp);

		for (auto& p : temp)
		{
			int i = p.first;
			int j = p.second;
			if (storage[i][j] == ' ')
				continue;

			side[storage[i][j]].insert({ i,j });
		}
	}

	return answer;
}
