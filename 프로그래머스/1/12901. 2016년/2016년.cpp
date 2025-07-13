#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> days = {"","FRI","SAT","SUN","MON","TUE","WED","THU"};
    vector<int> months = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int n = 0;
    for(int i =1; i< a ;i++)
        n += months[i];
    n += b;
    n--;
    cout << n << '\n';
    cout << n % 7 << '\n';
    answer = days[n % 7 + 1];
    return answer;
}