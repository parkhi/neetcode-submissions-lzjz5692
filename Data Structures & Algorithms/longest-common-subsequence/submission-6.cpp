class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length() , l2 = text2.length();

        vector<vector<int>> memo(l1+1, vector<int>(l2+1, 0));
        //cout<<l1<<" "<<l2<<endl;

        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                if(text1[i-1] == text2[j-1] ) {
                    memo[i][j] = memo[i-1][j-1] + 1;
                    //cout << "current side\n";
                }
                else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]) ;
                }
                //cout<<"i j memo[i][j] "<<i<<" "<<j<<" "<<memo[i][j]<<endl;
            }
        }

        return memo[l1][l2];
    }
};
