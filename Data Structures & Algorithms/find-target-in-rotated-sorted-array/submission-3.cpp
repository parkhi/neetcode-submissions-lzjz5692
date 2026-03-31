class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size()-1, m = 0;

        while(l <= r)
        {
            m = l + (r-l)/2;
            if(target == nums[m])
                return m;

            if(nums[m] < nums[l])
            {
                if((target >= nums[l]) || (target < nums[m]))
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if(target > nums[m])
                {
                    l = m + 1;
                }
                else if(target >= nums[l])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
