class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;

		for (int s : stones)
			pq.push(s);

		while (pq.size() >= 2)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();

			if (a == b)
				continue;

			int r = a - b;
			pq.push(r);
		}

		if (pq.empty())
			return 0;

		return pq.top();
	}
};