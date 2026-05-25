#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> student(3,0);
    
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size();i++)
    {
        if(answers[i] == v1[i % v1.size()])
            student[0]++;
        if(answers[i] == v2[i % v2.size()])
            student[1]++;
        if(answers[i] == v3[i % v3.size()])
            student[2]++;
    }
    
    int b = max(student[0],student[1]);
    b = max(b,student[2]);
    
    for(int i= 0; i <3;i++)
    {
        if(student[i] == b)
            answer.push_back(i+1);
    }
    return answer;
}