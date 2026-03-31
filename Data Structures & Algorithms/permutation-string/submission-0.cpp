class Solution {
public:
    bool isPerm(string s1, string s2)
    {
        if(s1.length() != s2.length())
            return false;

        unordered_map<char,int> hash;

        for(char c: s1)
        {
            hash[c]++;
        }
        for(char c: s2)
        {
            hash[c]--;
        }
        for(const auto& pair: hash)
        {
            if(pair.second != 0)
                return false;
        }    
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int sizes1 = s1.length(), sizes2 = s2.length();
        
        for(int r=sizes1-1, l=0; r<sizes2; l++,r++)
        {
            string s = s2.substr(l, sizes1);
            cout<<"string s is "<<s<<endl;

            if(isPerm(s,s1))
                return true;

        }
        return false;        
    }
};