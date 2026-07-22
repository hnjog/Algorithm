class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		queue<pair<int,int>> q;
		
		for (int i = 0; i < tickets.size(); i++)
		{
			q.push({ i,tickets[i] });
		}

		int time = 0;
		while (q.empty() == false)
		{
			time++;

			q.front().second--;
			if (q.front().second == 0)
			{
				if (q.front().first == k)
					break;

				q.pop();
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}

		return time;
	}
};