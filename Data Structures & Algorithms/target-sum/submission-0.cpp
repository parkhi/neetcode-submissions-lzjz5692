class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return dfs(nums, target, 0);
    }

    int dfs(vector<int>& nums, int target, int i) {
        
        if((i == nums.size()) && (target == 0)) {
            return 1;
        }
        if(i >= nums.size()) {
            return 0;
        }

        int res = 0;
        res = dfs(nums, target-nums[i], i+1) + dfs(nums, target+nums[i], i+1);

        return res;
    }
};
