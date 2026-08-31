class Solution {
public:
	bool judgeSquareSum(int c) {
		long sqc = sqrt(c) + 1;

		for (long i = 0; i <= sqc; i++)
		{
			long av = i * i;
			if (av > c)
				continue;

			long bv = sqrt(c - av);
			if (av + bv * bv == c)
				return true;
		}

		return false;
	}
};