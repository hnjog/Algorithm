#include <vector>
#include <set>
#include<queue>
using namespace std;

// 2D 벡터를 90도 회전시키는 함수
vector<vector<int>> rotate90(const vector<vector<int>>& matrix) {
    int n = matrix.size(); // 행렬의 크기
    vector<vector<int>> result(n, vector<int>(n)); // 결과 행렬 초기화

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 중앙을 기준으로 90도 회전
            result[j][n - 1 - i] = matrix[i][j];
        }
    }

    return result;
}

// 0~3 의 방향으로 움직인 벡터를 새로이 return
vector<vector<int>> moveDir(const vector<vector<int>>& matrix, int dir)
{
    int n = matrix.size();
    vector<vector<int>> result(n, vector<int>(n));

    switch (dir)
    {
    case 0: // left으로 이동
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > 0; j--)
            {
                result[i][j - 1] = matrix[i][j];
            }

            result[i][n - 1] = 0;
        }

    }
        break;
    case 1: // right
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n - 1; j++)
            {
                result[i][j + 1] = matrix[i][j];
            }

            result[i][0] = 0;
        }
    }
    break;
    case 2: // up
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                result[i - 1][j] = matrix[i][j];
            }
        }

        for(int i = 0; i < n;i++)
            result[n - 1][i] = 0;

    }
    break;
    case 3: // down
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i + 1][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < n; i++)
            result[0][i] = 0;

    }
    break;

    default:
        break;
    }

    return result;
}

// 해당 key가 정답인지 확인
bool isKeyRight(const vector<vector<int>>& key, const vector<vector<int>>& lock)
{
    const int keySize = key.size();
    const int lockSize = lock.size();

    for (int i = 0; i < lockSize; i++)
    {
        for (int j = 0; j < lockSize; j++)
        {
            if (i + keySize <= lockSize &&
                j + keySize <= lockSize)
            {
                vector<vector<int>> temp(lock);

                bool isFind = true;

                for (int a = 0; a < keySize; a++)
                {
                    for (int b = 0; b < keySize; b++)
                    {
                        if (temp[i + a][j + b] == 0 &&
                            key[a][b] == 1)
                        {
                            temp[i + a][j + b] = 1;
                        }
                        else if (temp[i + a][j + b] == 1 &&
                            key[a][b] == 1)
                        {
                            isFind = false;
                            break;
                        }
                    }

                    if (isFind == false)
                        break;
                }

                for (int i = keySize; i < lockSize - keySize; i++)
                {
                    for (int j = keySize; j < lockSize - keySize; j++)
                    {
                        if (temp[i][j] != 1)
                        {
                            isFind = false;
                            break;
                        }
                    }
                    if(isFind == false)
                        break;
                }
                
                if (isFind == true)
                    return true;
            }
        }
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // set에 넣어서 중복 확인하기
    set <vector<vector<int>>> keySet;
    const int kSize = key.size();
    const int lSize = lock.size();
    
    vector<vector<int>> newLock(lSize + kSize * 2, vector<int>(lSize + kSize * 2, 0));
    for (int i = kSize, a = 0; i < lSize + kSize; i++,a++)
    {
        for (int j = kSize, b = 0; j < lSize + kSize; j++,b++)
        {
            newLock[i][j] = lock[a][b];
        }
    }

    queue < vector<vector<int>> >q;
    q.push(key);

    while (q.empty() == false)
    {
        auto nowKey = q.front();
        q.pop();

        // 이미 찾은 키
        if (keySet.find(nowKey) != keySet.end())
        {
            continue;
        }

        if (isKeyRight(nowKey, newLock))
        {
            return true;
        }

        keySet.insert(nowKey);

        auto rV = rotate90(nowKey);
        q.push(rV);
        rV = rotate90(rV);
        q.push(rV);
        rV = rotate90(rV);
        q.push(rV);
    }

    return false;
}