class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int maxSeq = 1, tempSeq = 1;

        if(!nums.size())
            return 0;

        if(nums.size() == 1)
            return 1;

        for(int i=1 ; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i] == (nums[i-1]+1))
            {
                tempSeq++;
            }
            else
            {
                if(tempSeq > maxSeq)
                {
                    maxSeq = tempSeq;
                }
                tempSeq = 1;
            }

        }

        return max(tempSeq, maxSeq);
    }
};
