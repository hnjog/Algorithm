class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int> vm;
		vm["I"] = 1;
		vm["V"] = 5;
		vm["X"] = 10;
		vm["L"] = 50;
		vm["C"] = 100;
		vm["D"] = 500;
		vm["M"] = 1000;
		vm["IV"] = 4;
		vm["IX"] = 9;
		vm["XL"] = 40;
		vm["XC"] = 90;
		vm["CD"] = 400;
		vm["CM"] = 900;


		int ret = 0;

		string temp = "";
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			temp.push_back(c);

			if (vm.find(temp) == vm.end())
			{
				temp.pop_back();
				i--;
				ret += vm[temp];
				temp.clear();
			}
		}

		ret += vm[temp];

		return ret;
	}
};