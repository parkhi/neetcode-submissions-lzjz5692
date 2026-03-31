class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size,0);
        stack<pair<int, int>> hold;

        for( int i=0; i<temperatures.size(); i++)
        {
            while(!hold.empty() && (hold.top().first < temperatures[i]))
            {
                result[hold.top().second] = i - hold.top().second;
                hold.pop();
            }

            hold.push(make_pair(temperatures[i], i));
        }

        return result;
    }
};
