#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int a : arr1)
    {
        string temp = "";
        
        while(a > 0)
        {
            if(a % 2 == 1)
            {
                temp.push_back('#');
            }
            else
            {
                temp.push_back(' ');
            }
            
            a/=2;
        }
        
        reverse(temp.begin(),temp.end());
        
        string zt = "";
        int ts = temp.size();
        while(ts < n)
        {
            zt.push_back(' ');
            ts++;
        }
        
        if(zt.size() > 0)
        {
            temp = zt + temp;
        }
        
        answer.push_back(temp);
    }
    
    for(int i =0;i<n;i++)
    {
        string temp = "";
        int a = arr2[i];
        
        while(a > 0)
        {
            if(a % 2 == 1)
            {
                temp.push_back('#');
            }
            else
            {
                temp.push_back(' ');
            }
            
            a/=2;
        }
        
        reverse(temp.begin(),temp.end());
        
        string zt = "";
        int ts = temp.size();
        while(ts < n)
        {
            zt.push_back(' ');
            ts++;
        }
        
        if(zt.size() > 0)
        {
            temp = zt + temp;
        }
        for(int j =0; j < n;j++)
        {
            if(temp[j] == '#')
            {
                answer[i][j] = '#';
            }
        }
    }
    
    return answer;
}