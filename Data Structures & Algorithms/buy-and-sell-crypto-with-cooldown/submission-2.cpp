class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) {
            return 0;
        }
        vector<int> memo(n+1, -1);
        return maxP(0, prices.size(), prices, memo);
    }

    int maxP(int i, int n, vector<int>& prices, vector<int>& memo) {
        if(i >= n-1 || i<0) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        }

        for(int j=i+1; j<n; j++) {
            memo[i] = max(memo[i],max((maxP(j+2, n, prices, memo) + prices[j]-prices[i]), maxP(i+1, n, prices, memo)));
        }
         
        return memo[i];
    }
};
