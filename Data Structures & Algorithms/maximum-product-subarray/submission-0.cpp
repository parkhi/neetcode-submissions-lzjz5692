class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN, cur;

        for(int i=0; i<size; i++) {
            cur = nums[i];
            res = max(res, cur);

            for(int j=i+1; j<size; j++) {
                cur *= nums[j];
                res = max(res, cur);
            }
        }
        
        return res;      
    }        
};
