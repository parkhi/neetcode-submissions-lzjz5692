class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> elem;
        int l=0, r=0;

        while(r<nums.size())
        {
            if(r-l <= k)
            {
                if(elem.find(nums[r]) == elem.end())
                {
                    elem.insert(nums[r]);
                    r++;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                elem.erase(nums[l]);
                l++;
            }

        }

        return false;        
    }
};