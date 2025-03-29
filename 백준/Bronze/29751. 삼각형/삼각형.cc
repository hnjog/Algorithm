#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
    int w,h;
    cin >> w >> h;
    double result = double(w) * h /2;
    cout << fixed << setprecision(1);
    cout << result;
}