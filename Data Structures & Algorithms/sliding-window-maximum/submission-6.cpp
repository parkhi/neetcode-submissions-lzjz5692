class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int p1 = 0, p2 = 0, cmax;
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxhp;
        vector<int> res;

        if(nums.size() == 1) {
            return {nums[0]};
        }
        if(k == 1) {
            return nums;
        }

        while(p2 < k) {
            maxhp.push({nums[p2], p2});
            p2++;
        }
        p2 = k-1;
        while(p2 < nums.size()) {
            cout<<"p1 p2 maxhp.top().second " <<p1 <<" "<<p2<< " "<<maxhp.top().second<<endl;
            while(!((p1 <= maxhp.top().second) && (maxhp.top().second <= p2))) {
                cout<<"popping "<<maxhp.top().second<<endl;
                    maxhp.pop();
            }
            cmax = maxhp.top().first;
            res.push_back(cmax);
            p2++;
            if(p2 < nums.size()) {
                maxhp.push({nums[p2], p2});
            }
            p1++;
        }

        return res;
    }
};
