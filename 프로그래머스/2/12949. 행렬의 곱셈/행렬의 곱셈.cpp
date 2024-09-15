#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int ar1Size = arr1.size();
    int ar1XSize = arr1[0].size();
    int ar2XSize = arr2[0].size();

    // A X B * C X D = A X D 행렬
    vector<vector<int>> answer(ar1Size, vector<int>(ar2XSize, 0));


    for (int i = 0; i < ar1Size; i++) // A
    {
        for (int j = 0; j < ar2XSize; j++) // D
        {
            int sum = 0;
            for (int k = 0; k < ar1XSize; k++) // B C 
            {
                sum += (arr1[i][k] * arr2[k][j]);
            }
            answer[i][j] = sum;
        }
    }

    return answer;
}