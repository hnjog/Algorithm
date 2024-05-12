#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    const int t2[4] = {1,3,4,5};
    const int t3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int size = answers.size();
    
    int c1 = 0, c2 = 0, c3 = 0;
    
    for(int i = 0; i < size; i++)
    {
        int a = answers[i];
        
        if(a == i % 5 + 1)
        {
            c1++;
        }
        
        // 0 2 4
        if(i % 2 == 0)
        {
            if(a == 2)
            {
                c2++;
            }
        }
        else
        {
            if(a == t2[(i / 2) % 4])
            {
                c2++;
            }
        }
        
        if(a == t3[i%10])
        {
            c3++;
        }
    }
    
    vector<int> cs;
    cs.push_back(c1);
    cs.push_back(c2);
    cs.push_back(c3);
    
    int index = 1;
    int best = cs[0];
    answer.push_back(1);
    
    for(int i = 1; i <= 2; i++)
    {
        if(cs[i] == best)
        {
            answer.push_back(i + 1);
        }
        else if(cs[i] > best)
        {
            best = cs[i];
            answer.clear();
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}