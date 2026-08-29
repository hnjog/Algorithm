class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(),
			[](const vector<int>& a, const vector<int>& b)
			{
				if (a[0] == b[0])
					return a[1] < b[1];
				return a[0] < b[0];
			});


		vector<vector<int>> ret;

		vector<int> now;

		for (auto& i : intervals)
		{
			if (now.empty())
			{
				now = i;
				continue;
			}

			if (now[1] >= i[0])
			{
				now[1] = max(now[1], i[1]);
			}
			else
			{
				ret.push_back(now);
				now = i;
			}
		}

		if (now.empty() == false)
		{
			ret.push_back(now);
		}

		return ret;
	}
};