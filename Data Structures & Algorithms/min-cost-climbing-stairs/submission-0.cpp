class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int size = cost.size();
        int arr[size+1];

        arr[0] = 0;
        arr[1] = min(cost[0],0);

        for(int i =2; i<=size; i++) {
            arr[i] = min(arr[i-1] + cost[i-1], arr[i-2] + cost[i-2]);
        }

        return arr[size];
        
    }
};
