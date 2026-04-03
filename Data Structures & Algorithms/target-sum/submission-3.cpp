class Solution {
public:
    vector<vector<int>> memo;
    int totalSum;
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        memo.resize(n, vector<int>(2 * totalSum + 1 + target, INT_MIN));

        return dfs(nums, target, 0);
    }

    int dfs(vector<int>& nums, int target, int i) {
        
        if(i == nums.size()) {
            return (target == 0);
        }
        if(memo[i][target+totalSum] != INT_MIN) {
            return memo[i][target+totalSum];
        }

        memo[i][target+totalSum] = dfs(nums, target-nums[i], i+1) + dfs(nums, target+nums[i], i+1);
        cout<<"memo[i][target+totalSum] "<<i<<" "<<target<<" "<<memo[i][target+totalSum]<<endl;
        return memo[i][target+totalSum];
    }
};
