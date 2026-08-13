class Solution {
	string maskEmail(const string& origin)
	{
		size_t pos = origin.find('@');
		string ret = "";
		ret.push_back(tolower(origin[0]));
		for (int i = 0; i < 5; i++)
			ret.push_back('*');
		ret.push_back(tolower(origin[pos - 1]));

		for (size_t i = pos; i < origin.size(); i++)
		{
			ret.push_back(tolower(origin[i]));
		}

		return ret;
	}

	string maskPN(const string& origin)
	{
		string ret = "";
		vector<char> vs;
		for (char c : origin)
		{
			if (isdigit(c))
				vs.push_back(c);
		}

		if (vs.size() > 10)
		{
			ret.push_back('+');
			for (int i = 0; i < vs.size() - 10; i++)
			{
				ret.push_back('*');
			}
			ret.push_back('-');
		}

		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 3; i++)
			{
				ret.push_back('*');
			}
			ret.push_back('-');
		}
		
		for (int i = vs.size() - 4; i < vs.size(); i++)
		{
			ret.push_back(vs[i]);
		}

		return ret;
	}

public:
	string maskPII(string s) {
		bool bEmail = s.find('@') != string::npos;

		if (bEmail)
			return maskEmail(s);

		return maskPN(s);
	}
};