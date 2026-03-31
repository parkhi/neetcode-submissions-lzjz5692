#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        int numl, numr, res=0;

        for ( string c : tokens)
        {
            if ((eval.size() >= 2) && (c == "+" || c == "-" || c == "*" || c == "/"))
            {
                numr = eval.top();
                eval.pop();
                numl = eval.top();
                eval.pop();

                if (c == "+")
                    res = numl + numr;
                else if (c == "-")
                    res = numl - numr;
                else if (c == "*")
                    res = numl * numr;
                else
                    res = numl / numr;

                eval.push(res);
            }
            else 
                eval.push(stoi(c));

            res = eval.top();
        }
        return res;
    }
        
};