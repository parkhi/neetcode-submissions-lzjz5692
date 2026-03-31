class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int res = 0;

        for(int i=0 ; i<len ; i++) {
            // check for odd length pal
            int r = 0;
            while(i-r>=0 && i+r <len && s[i-r] == s[i+r]){
                res++;
                r++;
            }


            // check for even length pal
            r = 0;
            while(i-r>=0 && i+r <len && s[i-r] == s[i+1+r]){
                res++;
                r++;
            }
        }
        //cout<< "index and len "<<index<<" "<<plen<<endl;

        return res;

        
    }
};
