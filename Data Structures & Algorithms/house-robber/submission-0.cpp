class Solution {
public:
    int rob(vector<int>& nums) {

        int arr[nums.size()];

        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);

        for(int i=2;i<nums.size(); i++) {
            arr[i] = max(nums[i]+arr[i-2], arr[i-1]);
        }

        return arr[nums.size()-1];
        
    }
};
