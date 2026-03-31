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
            while((nums[i] == (nums[i-1]+1)) || (nums[i] == nums[i-1]))
            {
                if (nums[i] == (nums[i-1]+1))
                {
                    tempSeq++;
                }
                i++;
            }            
            if(tempSeq > maxSeq)
            {
                maxSeq = tempSeq;
            }
            tempSeq = 1;

        }

        return maxSeq;
    }
};
