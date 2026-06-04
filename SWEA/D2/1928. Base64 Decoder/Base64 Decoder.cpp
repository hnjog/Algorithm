#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

string decode(unordered_map<char, int>& umap, string& buf)
{
	string ret;
	int v = 0;
	for (char c : buf)
	{
		v += umap[c];
		v <<= 6;
	}
	v >>= 6;

	for (int i = 0; i < 3; i++)
	{
		int t = v & 0xFF;
		ret.push_back(t);
		v >>= 8;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	const string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	unordered_map<char, int> umap;
	int idx = 0;

	for (char c : str)
	{
		umap[c] = idx;
		idx++;
	}
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string temp;
		cin >> temp;

		/*
			인코딩 방식
			- 24비트 버퍼의 위쪽부터 한 바이트씩 3바이트를 집어넣음
			- 버퍼의 위쪽부터 6비트씩 잘라서 그 값을 Encoding함

			디코딩은 반대이면 됨
			- 문자 하나를 읽어 0~63값으로 변환 (이 녀석들은 총 6비트)
			- 이렇게 4개를 읽어 24비트를 읽은 후
			- 8비트씩 다시 한 바이트로 변경 (char 캐스팅)
		*/

		string ret;
		string buf;
		for (char c : temp)
		{
			buf.push_back(c);

			if (buf.size() >= 4)
			{
				ret += decode(umap, buf);
				buf.clear();
			}
		}

		cout << '#' << test_case << ' ' << ret << '\n';

	}
	return 0;
}