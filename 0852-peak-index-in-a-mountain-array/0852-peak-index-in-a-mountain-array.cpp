class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left = 1;
		int right = arr.size() - 2;

		while (left != right)
		{
			int mid = (left + right) / 2;

			int mv = arr[mid];
			int lv = arr[mid - 1];
			int rv = arr[mid + 1];

			if (lv < mv && mv > rv)
			{
				return mid;
			}

			if (lv > mv)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}

		return (left + right) / 2;
	}
};