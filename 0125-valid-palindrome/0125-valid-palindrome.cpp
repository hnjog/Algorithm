class Solution {
public:
	bool isPalindrome(string s) {
		string temp;

		for (char c : s)
		{
			if ((c >= 'a' && c <= 'z') ||
				isdigit(c))
				temp.push_back(c);
			else if (c >= 'A' && c <= 'Z')
				temp.push_back(tolower(c));
		}

		int tsize = temp.size();
		if (tsize == 0)
			return true;

		for (int i = 0; i <= tsize / 2; i++)
		{
			if (temp[i] != temp[tsize - 1 - i])
				return false;
		}

		return true;
	}
};