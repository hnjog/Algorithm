class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> vs;
        for (string& str : tokens)
        {
            if (str.size() == 1 &&
                (str[0] == '+' ||
                str[0] == '-' || 
                str[0] == '*' || 
                str[0] == '/'))
            {
                int a1 = vs.back();
                vs.pop_back();
                int a2 = vs.back();
                vs.pop_back();

                char v = str[0];
                int vv = 0;

                switch (v)
                {
                case '+':
                {
                    vv = a2 + a1;
                }
                    break;
                case '-':
                {
                    vv = a2 - a1;
                }
                    break;
                case '*':
                {
                    vv = a2 * a1;
                }
                    break;
                case '/':
                {
                    vv = a2 / a1;
                }
                    break;
                }

                vs.push_back(vv);
            }
            else
            {
                vs.push_back(stoi(str));
            }
        }

        return vs.back();
    }
};