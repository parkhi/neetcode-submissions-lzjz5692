class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        memo[0] = 1;
        return canjump(nums, nums.size()-1, memo);
    }

    bool canjump(vector<int>& nums, int ind, vector<int>& memo) {
        //cout<<"ind is "<<ind<<endl;

        if(memo[ind] != -1) {
            return memo[ind];
        }
        for(int i=ind-1; i>=0; i--) {
            //cout<<"nums[i] "<<nums[i] <<" ind-i "<<ind-i<<endl;
            if((nums[i] >= (ind-i))) {
                if( canjump(nums, i, memo)) {
                    memo[i] = 1;
                    return true;
                }
            }
        }
        memo[ind] = 0;
        return false;
    }
};
