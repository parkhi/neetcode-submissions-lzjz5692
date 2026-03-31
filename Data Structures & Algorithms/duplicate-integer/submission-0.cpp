class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique_data ;

        for (int i=0; i< nums.size() ; i++)
        {
            if(unique_data.find(nums[i]) == unique_data.end())
                unique_data.insert(nums[i]);
            else
                return true;
        }

        return false;
    }
};