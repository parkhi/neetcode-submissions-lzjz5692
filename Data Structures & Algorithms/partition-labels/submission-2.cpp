class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }
        vector<int> res;

        for(int i=0; i<s.length(); i++) {
            unordered_set<char> st;

            int len = mp[s[i]];
            cout<<"len "<<len <<endl;
            st.insert(s[i]);

            for(int j=i+1; j<i+len; j++) {
                if(st.find(s[j]) == st.end()) {
                    len += mp[s[j]];
                    st.insert(s[j]);
                }
            }
            res.push_back(len);
            
            i = i+len-1;
        }     

           return res;   
    }
};
