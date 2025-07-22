#include<iostream>

using namespace std;

int main()
{
	// 2번째는 5의 제곱이고
	//
	// 5번째는 33의 제곱이다
	// 
	// 3
	// 5
	// ...
	// ...
	// 33
	// 
	// 
	// 3 (2)
	// 5 (4)
	// 9 (8)
	// 17 (16)
	// 33
	//

	int n;
	cin >> n;

	long long result = 3;

	int v = 2; // 여기에 2를 곱해나간다

	for (int i = 1; i < n; i++)
	{
		result += v;
		v *= 2;
	}
	
	result *= result;

	cout << result;
}