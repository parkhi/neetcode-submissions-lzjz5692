class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return nums[0];
        }

        int arr[n];

        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        if(n == 2) {
            return arr[1];
        }

        for(int i=2;i<n; i++) {
            arr[i] = max(nums[i]+arr[i-2], arr[i-1]);
        }
        int last = n-1;
        arr[last] = arr[last-1];

        int sol1 = arr[last];

        arr[0] = 0;
        arr[1] = nums[1];

        for(int i=2;i<n; i++) {
            arr[i] = max(nums[i]+arr[i-2], arr[i-1]);
        }

        arr[last] = max( arr[last-1]- nums[last-1]+nums[last],
                         arr[last-2]+nums[last]);

        return max(sol1, arr[n-1]);
        
        
    }
};
