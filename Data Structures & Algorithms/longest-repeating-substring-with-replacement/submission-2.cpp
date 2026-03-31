class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int maxfreq = 0, l=0, maxlen=0;
        
        for(int r=0; r<s.length(); r++)
        {
            freq[s[r]-'A']++;
            maxfreq = *max_element(freq, freq+26);
            cout<<"maxfreq is "<<maxfreq<<endl;

            if((r-l+1-maxfreq) > k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            else
            {
                maxlen = max(maxlen, r-l+1);
            }
        }

        return maxlen;

    }
};