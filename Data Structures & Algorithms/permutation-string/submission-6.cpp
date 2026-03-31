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
        
        for(int l=0; l<=sizes2-sizes1; l++)
        {
            while((l <=sizes2-sizes1) && (s1.find(s2[l])==string::npos)) 
                l++;
            cout<<"l "<<l<<" sizes1 "<<sizes1<<endl;
            string s = s2.substr(l, sizes1);
            cout<<"s "<<s<<endl;

            if(isPerm(s,s1))
                return true;

        }
        return false;        
    }
};