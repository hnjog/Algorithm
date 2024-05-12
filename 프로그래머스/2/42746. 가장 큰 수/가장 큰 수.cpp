#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool {
	string sa = to_string(a);
	string sb = to_string(b);

	return sa + sb > sb + sa;
	});

    for (auto a : numbers)
    {
        if (answer == "0" && a == 0)
	        continue;
        
        answer += to_string(a);
    }

    int b = 10;

    return answer;
}