#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    string strX = to_string(x);
    
    for(int i = 0; i < strX.size();i++)
    {
        sum += (strX[i] - '0');
    }
    
    if(x % sum == 0)
        return true;
    
    return false;
}