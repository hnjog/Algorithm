class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		int n = prices.size();
		vector<int> ret(n, 0);
		vector<pair<int, int>> st;

		for (int i = 0; i < n; i++)
		{
			if (st.empty())
				st.push_back({ i,prices[i] });
			else
			{
				if (prices[i] <= st.back().second)
				{
					while (st.empty() == false &&
						prices[i] <= st.back().second)
					{
						ret[st.back().first] = st.back().second - prices[i];
						st.pop_back();
					}
				}

				st.push_back({ i,prices[i] });
			}
		}

		while (st.empty() == false)
		{
			ret[st.back().first] = st.back().second;
			st.pop_back();
		}

		return ret;
	}
};