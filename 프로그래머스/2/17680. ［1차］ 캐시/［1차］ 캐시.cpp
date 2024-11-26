#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Compare
{
	bool operator()(pair<string, int>& a, pair<string, int>& b)
	{
		return a.second > b.second;
	}
};

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int cSize = cities.size();

	if (cacheSize == 0)
	{
		answer = cSize * 5;
		return answer;
	}

	// 뒤쪽값은 index와 빈도수
	unordered_map<string, int> m;
	int sumI = -1;

	for (int i =0;i<cSize;i++)
	{
		string city = cities[i];
		for (char& c : city)
		{
			c = toupper(c);
		}

		if (m.find(city) == m.end())
		{
			answer += 4;

			if (m.size() == cacheSize)
			{
				priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

				for (auto& a : m)
				{
					pq.push(a);
				}

				auto& p = pq.top();
				m.erase(p.first);
			}
		}

		answer++;
		m[city] = i;
	}

	return answer;
}