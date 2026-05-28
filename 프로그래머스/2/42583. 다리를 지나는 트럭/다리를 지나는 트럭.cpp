#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	queue<pii> q;
	int sum = 0;
	int tidx = 0;

	while (q.empty() == false ||
		tidx < truck_weights.size())
	{
		while (q.empty() == false &&
            q.front().second <= time)
        {
            sum -= q.front().first;
            q.pop();
        }

		if (tidx < truck_weights.size() &&
			truck_weights[tidx] + sum <= weight &&
			q.size() < bridge_length)
		{
			q.push({ truck_weights[tidx], time + bridge_length });
			sum += truck_weights[tidx];
			tidx++;
			time++;
			continue;
		}

		time = q.front().second;
		sum -= q.front().first;
		q.pop();
	}

	return time;
}