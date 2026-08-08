class Solution {
public:
	bool isPossible(vector<int>& target) {
		int tsize = target.size();
		priority_queue<long long> copy;

		long long restSum = 0;

		for (int i = 0; i < tsize; i++)
		{
			if (target[i] <= 0)
				return false;

			copy.push(target[i]);
			restSum += target[i];
		}

		if (copy.size() == 0)
			return true;

		while (copy.top() != 1)
		{
			long long mv = copy.top();
			copy.pop();

			long long rs = restSum - mv;
			if (rs == 1)
				break;

			if (rs == 0 ||
				mv <= rs)
				return false;

			long long nv = mv % rs;
			if (nv == 0)
				return false;

			copy.push(nv);
			restSum = nv + rs;
		}

		return true;
	}
};