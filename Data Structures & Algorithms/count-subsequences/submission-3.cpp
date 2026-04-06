class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length(), l2 = t.length();

        if(l1 == l2) {
            return s == t;
        }
        cout<<"here\n";

        vector<vector<uint>> memo(l1+1, vector<uint>(l2+1, 0));
        for(int i=0; i<=l1; i++) {
            memo[i][l2] = 1;
        }

        for(int i=l1-1; i>=0; i--) {
            for(int j=l2-1; j>=0; j--) {
                memo[i][j] = memo[i+1][j];
                if(s[i] == t[j]){
                    memo[i][j] += memo[i+1][j+1];
                    cout<<memo[i][j]<<endl;
                }
            }
        }
        return memo[0][0];
    }
};
