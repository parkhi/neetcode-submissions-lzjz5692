class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] > 0) break;
            
            if((i>0) && (nums[i]==nums[i-1]))
                continue;

            int j=i+1, k=nums.size()-1;
            
            while (j < k)
            {
                if((nums[j]+nums[k]+nums[i]) == 0)
                {
                    vector<int> triplet;
                    triplet.insert(triplet.end(), {nums[i], nums[j], nums[k]});
                    result.push_back(triplet);
                    j++;
                    k--;

                    while((j<k) && (nums[j] == nums[j-1]))
                        j++;
                }
                else if((nums[j]+nums[k]+nums[i]) > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }

        }

        return result;
    }
};
