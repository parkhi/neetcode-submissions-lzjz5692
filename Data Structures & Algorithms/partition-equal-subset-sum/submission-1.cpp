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

        return dfs(nums, 0, total);      
  
    }
    bool dfs(vector<int>& nums, int i, int target) {
        if(target == 0) {
            return true;
        }
        if(i == nums.size()) {
            return target == 0;
        }
        if(target < 0) {
            return false;
        }

        return dfs(nums, i+1, target) || dfs(nums, i+1, target-nums[i]);
    }
};
