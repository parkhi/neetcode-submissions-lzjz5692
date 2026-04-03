class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        int n = coins.size(), total = 0;

        sort(coins.begin(), coins.end());
        memo.resize(n+1, vector<int>(amount+1, -1));

        return dfs(amount, coins, 0);
        
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
