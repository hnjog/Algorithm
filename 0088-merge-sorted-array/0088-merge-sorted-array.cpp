class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0)
			return;
		
		if (m == 0)
		{
			nums1 = nums2;
			return;
		}

		vector<int> temp(m+n,0);
		int i1 = 0, i2 = 0;
		for (int i = 0; i < m + n; i++)
		{
			if (i1 >= m)
			{
				temp[i] = nums2[i2];
				i2++;
				continue;
			}

			if (i2 >= n)
			{
				temp[i] = nums1[i1];
				i1++;
				continue;
			}

			if (nums1[i1] < nums2[i2])
			{
				temp[i] = nums1[i1];
				i1++;
			}
			else
			{
				temp[i] = nums2[i2];
				i2++;
			}
		}

		nums1 = temp;
	}
};