class Solution {
public:
	vector<int> beautifulArray(int n) {
		vector<int> ret = { 1 };

		while (ret.size() < n)
		{
			vector<int> temp;
			temp.reserve(ret.size() * 2);

			for (int i : ret)
			{
				int v = i * 2 - 1;
				if(v <= n)
					temp.push_back(v);
			}

			for (int i : ret)
			{
				int v = i * 2;
				if (v <= n)
					temp.push_back(v);
			}

			ret = move(temp);
		}

		return ret;
	}
};