class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();

        int leftMax[size];
        int rightMax[size];
        int lmax = height[0], rmax = height[size-1];

        leftMax[0] = height[0];
        rightMax[size-1] = height[size-1];

        cout<< "leftMax " <<endl;

        for(int i=1; i<size; i++)
        {
            if(lmax < height[i])
                lmax = height[i];
    
            leftMax[i] = lmax;
            cout << leftMax[i] << " ";
        }

        cout<< "rightMax " <<endl;

        for(int i=size-2; i>=0; i--)
        {
            if(rmax < height[i])
                rmax = height[i];
    
            rightMax[i]=rmax;
            cout << rightMax[i] << " ";
        }

        int maxArea = 0, curArea = 0;
        for(int i=0; i<size-1; i++)
        {
            if((min(leftMax[i], rightMax[i]) - height[i]) > 0)
                curArea = min(leftMax[i], rightMax[i]) - height[i];
            else
                curArea = 0;
            
            maxArea += curArea;
        }

        return maxArea;
    }
};
