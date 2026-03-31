#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hashNums;

        for (int i=0; i<nums.size(); i++)
        {
            hashNums.insert({nums[i], i});
        }

        //cout << "size "<< hashNums.size()<<endl;

        for (int i=0; i<nums.size(); i++)
        {
            int bal = target - nums[i];

            if ((hashNums.count(bal)) && (hashNums[bal] != i))
            {
                if (i>hashNums[bal])
                    return {hashNums[bal], i};
                else 
                    return {i, hashNums[bal]};
            }
        }

        return {-1, -1};
    }
};