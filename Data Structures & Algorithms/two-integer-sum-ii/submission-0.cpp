class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int sum = 0, i=0, j=(numbers.size()-1);
        vector<int> result;
        
        while (i<j)
        {
            sum = numbers[i]+numbers[j];
            
            if (sum == target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                }
            else if (sum > target)
                j--;
            else
                i++;
        }

        return result;
    }
};
