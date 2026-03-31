class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> scores;
        int sum = 0;

        for(string s : operations)
        {
            if(s == "+")
            {
                if(scores.size() >= 2)
                {
                    int temp = scores.top();
                    scores.pop();
                    int t = temp;
                    temp += scores.top();
                    scores.push(t);
                    scores.push(temp);

                    sum += temp;
                }

            }
            else if(s == "D")
            {
                if(!scores.empty())
                {
                    scores.push(scores.top()*2);
                    sum += scores.top();
                }
            }
            else if(s == "C")
            {
                if(!scores.empty())
                {
                    sum -= scores.top();
                    scores.pop();
                }
            }
            else
            {
                scores.push(stoi(s));
                sum += stoi(s);
            }
        }
        
        return sum;
        
    }
};