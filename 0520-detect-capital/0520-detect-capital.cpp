class Solution {
public:
	bool detectCapitalUse(string word) {
		
		bool bAllCap = false;
		bool bAllnc = false;
		if (word[0] >= 'a' && word[0] <= 'z')
		{
			bAllnc = true;
		}
		else
		{
			bAllCap = true;
		}
		int count = 0;
		for (int i = 1; i < word.size(); i++)
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
			{
				count++;
			}
		}

		if (bAllCap)
		{
			if (count > 0 && count < word.size() - 1)
				return false;
		}
		else
		{
			if (count > 0)
				return false;
		}

		return true;
	}
};