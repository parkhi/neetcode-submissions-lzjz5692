class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int plen = 0, index = 0;

        for(int i=0 ; i<len ; i++) {
            // check for odd length pal
            int r = 0;
            while(i-r>=0 && i+r <len && s[i-r] == s[i+r]){
                if(2*r+1 > plen) {
                    index = i-r;
                    plen = 2*r + 1;
                }
                r++;
            }


            // check for even length pal
            r = 0;
            while(i-r>=0 && i+r <len && s[i-r] == s[i+1+r]){
                if(2*r+2 > plen) {
                    index = i-r;
                    plen = 2*r + 2;
                }
                r++;
            }
        }
        cout<< "index and len "<<index<<" "<<plen<<endl;

        return s.substr(index, plen);

    }
};
