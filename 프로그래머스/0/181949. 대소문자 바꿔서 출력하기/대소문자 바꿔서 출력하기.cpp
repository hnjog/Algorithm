#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int d = 'A' - 'a';

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] += d;
        }
        else
        {
            str[i] -= d;
        }
    }

    cout << str;

    return 0;
}