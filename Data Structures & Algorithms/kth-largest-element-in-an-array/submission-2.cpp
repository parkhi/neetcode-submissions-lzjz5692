class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minhp;
        
        for(int num : nums) {
            minhp.push(num);

            if(minhp.size() == k+1) {
                minhp.pop();
            }
        }

        return minhp.top();
    }
};
