class Solution {
public:
	int strStr(string haystack, string needle) {
		size_t v = haystack.find(needle);
		if (v == string::npos)
			return -1;

		return v;
	}
};