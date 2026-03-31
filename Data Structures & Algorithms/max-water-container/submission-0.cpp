class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;

        int i=0, j=heights.size()-1;
        while (i<j)
        {
            int watcur = (j-i)*(min(heights[i], heights[j]));
            if (watcur > result)
                result=watcur;
            
            if(heights[i] < heights[j])
                i++;
            else
                j--;
        }

        return result;
        
    }
};
