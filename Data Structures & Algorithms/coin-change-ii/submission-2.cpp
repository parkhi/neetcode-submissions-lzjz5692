class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        int n = coins.size(), total = 0;

        sort(coins.begin(), coins.end());
        memo.resize(n+1, vector<int>(amount+1, 0));

        for(int i=0; i<=n; i++) {
            memo[i][0] = 1;
        }

        for(int i = n-1; i>=0; i--) {
            for(int j=0; j<=amount; j++) {
                if(j >= coins[i]) {
                    memo[i][j] = memo[i][j-coins[i]] + memo[i+1][j];
                }
            }
        }

        return memo[0][amount];
        
    }

    int dfs(int amount, vector<int>& coins, int i) {
        if(i >= coins.size()) {
            return 0;
        }
        if(amount == 0) {
            return 1;
        }
        if(memo[i][amount] != -1)
            return memo[i][amount];

        if(amount >= coins[i]) {
            memo[i][amount] = dfs(amount, coins, i+1) + dfs(amount - coins[i], coins, i);
        }
        else {
            memo[i][amount] = 0;
        }

        return memo[i][amount];
        
    }
};
