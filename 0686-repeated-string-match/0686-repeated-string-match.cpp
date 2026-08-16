class Solution {
public:
	int repeatedStringMatch(string a, string b) {
		string test = a;

		int ret = 1;

		while (true)
		{
			bool bFind = test.find(b) != string::npos;
			if (bFind)
				break;

			if (test.size() > b.size() + a.size() * 2)
				return -1;

			test.append(a);
			ret++;
		}

		return ret;
	}
};