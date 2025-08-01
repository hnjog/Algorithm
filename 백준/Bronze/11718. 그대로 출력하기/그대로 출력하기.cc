#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<string> vec;
    string l;
    while (getline(cin,l))
    {
        if (l.empty())
            break;

        vec.push_back(l);
    }

    for (string& s : vec)
    {
        cout << s << '\n';
    }

    return 0;
}