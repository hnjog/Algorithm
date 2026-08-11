class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string ret;
		int count = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			char c = toupper(s[i]);
			if (c != '-')
			{
				count++;
				ret.push_back(c);
			}

			if (count >= k)
			{
				ret.push_back('-');
				count = 0;
			}
		}

		while (ret.empty() == false &&
			ret.back() == '-')
		{
			ret.pop_back();
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};