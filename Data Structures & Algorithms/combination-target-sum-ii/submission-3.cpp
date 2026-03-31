class Solution {
vector<vector<int>> res;

void bt(vector<int>& nums, vector<int>& cur, int target, int ind) {

    if(target == 0) {
        res.push_back(cur);
        return;
    }
    if(target < 0 || ind >= nums.size()) {
        return;
    }
    cur.push_back(nums[ind]);
    bt(nums, cur, target-nums[ind], ind+1);
    cur.pop_back();

    while(ind+1 < nums.size() && nums[ind] == nums[ind+1]) {
        ind++;
    }
    bt(nums, cur, target, ind+1);
}

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> cur;

        sort(nums.begin(), nums.end());
        bt(nums, cur, target, 0);

        return res;

    }


};
