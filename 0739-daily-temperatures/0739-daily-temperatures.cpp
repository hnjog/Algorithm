class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> ret(n, 0);
		vector<pair<int, int>> st;

		for (int i = 0; i < n; i++)
		{
			if (st.empty())
				st.push_back({ i,temperatures[i] });
			else
			{
				if (temperatures[i] > st.back().second)
				{
					while (st.empty() == false &&
						temperatures[i] >st.back().second)
					{
						ret[st.back().first] = i - st.back().first;
						st.pop_back();
					}
				}

				st.push_back({ i,temperatures[i] });
			}
		}

		while (st.empty() == false)
		{
			ret[st.back().first] = 0;
			st.pop_back();
		}

		return ret;
	}
};