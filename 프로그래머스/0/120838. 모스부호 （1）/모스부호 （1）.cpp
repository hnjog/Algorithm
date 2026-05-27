#include <string>
#include <vector>
#include<sstream>
#include<algorithm>
#include<map>

using namespace std;

map<std::string, char> morse{
		{".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'},
		{"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'},
		{"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'},
		{"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'},
		{"-.--", 'y'}, {"--..", 'z'}
};

string solution(string letter) {
	string answer = "";

	istringstream iss(letter);
	vector<string> words;
	string word;

	while (iss >> word)
	{
		words.push_back(word);
	}

	for (int i = 0; i < words.size(); i++)
	{
		answer += morse[words[i]];
	}

	return answer;
}