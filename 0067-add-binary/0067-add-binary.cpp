class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		while (a.size() < b.size())
		{
			a.push_back('0');
		}
		while (a.size() > b.size())
		{
			b.push_back('0');
		}

		string ret(a.size(), '0');
		bool bUp = false;

		for (int i = 0; i < a.size(); i++)
		{
			char aa = a[i];
			char bb = b[i];

			if (bUp == false)
			{
				if ((aa == '0' &&
					bb == '1') ||
					(bb == '0' &&
						aa == '1'))
				{
					ret[i] = '1';
				}
				else if ((aa == '1' &&
					bb == '1'))
				{
					bUp = true;
				}
			}
			else
			{
				if ((aa == '0' &&
					bb == '0'))
				{
					ret[i] = '1';
					bUp = false;
				}
				else if ((aa == '0' &&
					bb == '1') ||
					(bb == '0' &&
						aa == '1'))
				{
					ret[i] = '0';
					bUp = true;
				}
				else
				{
					ret[i] = '1';
					bUp = true;
				}
			}
		}

		if (bUp)
			ret.push_back('1');

		reverse(ret.begin(), ret.end());

		return ret;
	}
};