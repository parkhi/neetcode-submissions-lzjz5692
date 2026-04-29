class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canjump(nums, nums.size()-1);
    }

    bool canjump(vector<int>& nums, int ind) {
        //cout<<"ind is "<<ind<<endl;

        if(ind == 0) {
            return true;
        }
        for(int i=ind-1; i>=0; i--) {
            //cout<<"nums[i] "<<nums[i] <<" ind-i "<<ind-i<<endl;
            if((nums[i] >= (ind-i))) {
                if( canjump(nums, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};
