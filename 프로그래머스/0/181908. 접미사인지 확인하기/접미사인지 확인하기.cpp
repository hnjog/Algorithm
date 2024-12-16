#include <string>

using namespace std;

int solution(string my_string, string is_suffix) {
    string t(my_string.begin() + my_string.size() - is_suffix.size(), my_string.end());
    
    if(t == is_suffix)
        return 1;
    
    return 0;
}