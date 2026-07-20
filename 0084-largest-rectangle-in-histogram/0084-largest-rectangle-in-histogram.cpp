class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int maxV = 0;
		vector<pair<int,int>> st;

		for (int i = 0; i < heights.size();i++)
		{
			int h = heights[i];

			if (st.empty() ||
				st.back().first <= h)
			{
				st.push_back({ h,i });
				continue;
			}

			int idx = i;
			while (st.empty() == false &&
				st.back().first > h)
			{
				int v = (i - st.back().second) * st.back().first;
				idx = st.back().second;
				maxV = max(v, maxV);
				st.pop_back();
			}

			st.push_back({ h,idx });
		}

		while (st.empty() == false)
		{
			int v = (heights.size() - st.back().second) * st.back().first;
			maxV = max(v, maxV);
			st.pop_back();
		}

		return maxV;
	}
};