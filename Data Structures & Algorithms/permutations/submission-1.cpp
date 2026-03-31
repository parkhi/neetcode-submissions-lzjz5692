class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int idx) {

        if(idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            backtrack(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);

        return res;
    }
};
