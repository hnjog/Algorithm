#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, double> md;
	md["A+"] = 4.5;
	md["A0"] = 4.0;
	md["B+"] = 3.5;
	md["B0"] = 3.0;
	md["C+"] = 2.5;
	md["C0"] = 2.0;
	md["D+"] = 1.5;
	md["D0"] = 1.0;
	md["F"] = 0.0;

	double dSum = 0.0;
	double v = 0.0;

	for (int i = 0; i < 20; i++)
	{
		string s1,s2,s3;
		cin >> s1 >> s2 >> s3;

		if (s3 == "P")
		{
			continue;
		}

		double dv = stod(s2) * md[s3];
		
		v += stod(s2);
		dSum += dv;
	}

	double result = dSum / v;

	cout << result;

	return 0;
}