class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN, curmax = 1, curmin = 1;


        for(int i=0; i<size; i++) {
            int pmax = curmax;
            pmax = max(max(nums[i], curmax*nums[i]), curmin*nums[i]);
            curmin = min(min(nums[i], curmax*nums[i]), curmin*nums[i]);
            curmax = pmax;
            res = max(res, curmax);
            //cout<<"curmax curmin res "<<curmax<<" "<<curmin<<" "<<res<<endl;
        }

        
        return res;      
    }        
};
