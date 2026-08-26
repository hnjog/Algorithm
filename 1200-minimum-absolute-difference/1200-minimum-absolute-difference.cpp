class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());

		int minDif = INT_MAX;

		for (int i = 0; i < arr.size() - 1; i++)
		{
			int dif = arr[i + 1] - arr[i];
			if (dif < minDif)
				minDif = dif;
		}

		vector<vector<int>> ret;

		for (int i = 0; i < arr.size() - 1; i++)
		{
			int dif = arr[i + 1] - arr[i];
			if (dif == minDif)
				ret.push_back({ arr[i],arr[i + 1] });
		}

		return ret;
	}
};
