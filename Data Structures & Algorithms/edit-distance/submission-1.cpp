class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();

        if(word1 == word2) {
            return 0;
        }
        if(word1 == "") {
            return l2;
        }
        if(word2 == "") {
            return l1;
        }

        vector<vector<uint>> memo(l1+1, vector<uint>(l2+1, 0));
        for(int i=0; i<=l1; i++) {
            memo[i][l2] = l1-i;
        }
        for(int j=0; j<=l2; j++) {
            memo[l1][j] = l2-j;
        }

        for(int i=l1-1; i>=0; i--) {
            for(int j=l2-1; j>=0; j--) {
                if(word1[i] == word2[j]) {
                    memo[i][j] = memo[i+1][j+1];
                }
                else {
                    memo[i][j] = 1+ min(min(memo[i][j+1], memo[i+1][j]), memo[i+1][j+1]);
                }
            }
        }

        return memo[0][0];
    }
};
