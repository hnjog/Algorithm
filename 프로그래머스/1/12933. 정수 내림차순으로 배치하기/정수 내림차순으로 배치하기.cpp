#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string temp = to_string(n);
    vector<char> vec;
    
    for(char c : temp)
    {
        vec.push_back(c);
    }
    
    sort(vec.begin(),vec.end(),greater<int>());
    string temp2;
    for(char c : vec)
    {
        temp2 += c;
    }
    
    answer = stoll(temp2);
    
    return answer;
}