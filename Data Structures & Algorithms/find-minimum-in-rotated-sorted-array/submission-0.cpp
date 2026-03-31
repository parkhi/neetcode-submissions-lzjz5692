class Solution {
public:
    int findMin(vector<int> &nums) {

        int l = 0, r = nums.size()-1;
        int m = (l + r)/2;

        while(l <= r)
        {
            m = l + (r-l)/2;

            if(nums[l] <= nums[r])
                return nums[l];
            else
            {
                if(nums[m] > nums[r])
                {
                    l = m+1;
                }
                else
                {
                    r = m;
                }
            }
        }
        return nums[l];        
    }
};
