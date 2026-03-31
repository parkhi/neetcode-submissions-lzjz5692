class Solution {
public:
    unordered_map<int,int> memo;

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins , amount);
        return (res == INT_MAX ? -1 : res);
    }

    int dfs(vector<int>& coins, int amount) {
        int res = INT_MAX;
        if(amount == 0) {
            return 0;
        }
        if(memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        for(int coin : coins) {
            if(amount - coin >= 0) {
                int res1 = dfs(coins, amount-coin);
                if(res1 != INT_MAX) {
                    res = min(res, res1 + 1);
                }
            }
        }
        memo[amount] = res;
        return res;        
    }
};
