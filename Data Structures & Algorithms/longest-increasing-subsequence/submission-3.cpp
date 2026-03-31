class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
             return a.first > b.first ;
        };

        multiset<pair<int,int>, decltype(cmp)> frq(cmp);
        int res = 1;

        int size = nums.size();
        frq.insert({1, size-1});

        for(int j=size-2; j>=0; j--) {
            bool done = false;
            for(auto p : frq) {
                int x = p.second;
                if(nums[x] > nums[j]) {
                    frq.insert({p.first+1, j});
                    done = true;
                    res = max(res, p.first+1);
                    cout<<"change ..................\n";
                for(auto p : frq) {
                    int x = p.second;
                    cout<<"{freq, index} "<<p.first <<" "<<p.second<<endl;
                    }
                    break;
                }
                   // cout<<"{p.first+1, j} "<<p.first+1 <<" "<<j<<endl;}
                }
                if(!done) {
                    frq.insert({1, j});
                }
            }

            return res;
        }
};
