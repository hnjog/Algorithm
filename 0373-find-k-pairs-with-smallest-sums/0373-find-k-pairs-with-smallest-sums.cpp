class Solution {

	struct Infos
	{
		int y, x;
		int v1, v2;
	};

	struct Compare
	{
		bool operator()(const Infos& a, const Infos& b)
		{
			return (a.v1 + a.v2) > (b.v1 + b.v2);
		}
	};

public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<Infos, vector<Infos>, Compare> pq;

		int n1 = nums1.size(), n2 = nums2.size();
		int i1 = 0, i2 = 0;

		for (int i = 0; i < n2; i++)
			pq.push({ 0,i, nums1[0],nums2[i] });

		vector<vector<int>> ret;

		while (ret.size() < k)
		{
			Infos i = pq.top();
			pq.pop();

			ret.push_back({ i.v1,i.v2 });
			
			if (i.y < n1 - 1)
			{
				pq.push({ i.y + 1,i.x,nums1[i.y + 1],nums2[i.x] });
			}
		}

		return ret;
	}
};