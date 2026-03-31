class Solution {
public:
    bool isValid(string s) {
        stack<char> match;

        for (char c : s)
        {
            if((c == '(')||(c == '{')||(c == '['))
                match.push(c);
            else if((!match.empty()) &&
                    (((c == ')') && (match.top() == '(')) ||
                    ((c == '}') && (match.top() == '{')) ||
                    ((c == ']') && (match.top() == '['))))
            {
                match.pop();
            }
            else
                match.push(c);
        }
        if(match.empty())
            return true;
        return false;
        
    }
};
