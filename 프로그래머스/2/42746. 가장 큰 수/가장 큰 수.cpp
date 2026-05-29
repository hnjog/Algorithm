#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    int n = numbers.size();
    vector<string> nums;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        nums.push_back(to_string(numbers[i]));
    }

    sort(nums.begin(), nums.end(), [](const string& a, const string& b)
        {
            string ab = a + b;
            string ba = b + a;

            if (ab == ba)
                return a.size() > b.size();

            return ab > ba;
        });

    for (string& str : nums)
    {
        answer.append(str);
    }

    if (answer[0] == '0')
        answer = "0";

    return answer;
}