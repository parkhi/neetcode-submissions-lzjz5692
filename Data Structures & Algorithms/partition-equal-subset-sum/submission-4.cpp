class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        for(int num : nums ) {
            total += num;
        }
        if(total % 2) {
            return false;
        }
        total = total/2;
        vector<bool> dp(total+1, false);
        dp[0] = true;

        for(int i=0; i<nums.size(); i++) {
            for(int j = total; j>=nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[total];    
  
    }
    // bool dfs(vector<int>& nums, int i, int target, vector<bool>& dp) {
    //     if(target == 0) {
    //         return true;
    //     }
    //     if(i == nums.size()) {
    //         return target == 0;
    //     }
    //     if(target < 0) {
    //         return false;
    //     }
    //     return dfs(nums, i+1, target) || dfs(nums, i+1, target-nums[i]);
    // }
};
