class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();

        if(l3 != l1+l2) {
            return false;
        }

        vector<vector<bool>> memo(l1+1, vector<bool>(l2+1, false));
        memo[l1][l2] = true;

        for(int i=l1; i>=0; i--) {
            for(int j=l2; j>=0; j--) {
                if((i<l1) && (s1[i] == s3[i+j]) && memo[i+1][j]) {
                    memo[i][j] = true;
                }
                if((j<l2) && (s2[j] == s3[i+j]) && memo[i][j+1]) {
                    memo[i][j] = true;
                }
            }
        }
             return memo[0][0];
    }

   
};
