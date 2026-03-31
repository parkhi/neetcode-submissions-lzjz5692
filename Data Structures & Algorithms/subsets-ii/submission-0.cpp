class Solution {
vector<vector<int>> res;

void bt(vector<int>& nums, vector<int>& cur, int ind) {

    if(ind == nums.size()) {
        res.push_back(cur);
        return;
    }

    cur.push_back(nums[ind]);
    bt(nums, cur, ind+1);
    cur.pop_back();

    while(ind < nums.size() && nums[ind] == nums[ind+1]) {
        ind++;
    }
    bt(nums, cur, ind+1);
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;

        sort(nums.begin(), nums.end());
        bt(nums, cur, 0);

        return res;

    }


};
