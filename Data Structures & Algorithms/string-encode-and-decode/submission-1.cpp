class Solution {
public:

    string encode(vector<string>& strs) {

         
        if (strs.size()==0)
            return "";

        string result="";
        int len;
        
        for (string str: strs)
        {
            len = str.length();
            result += to_string(len)+"#"+str;
        }
        
        cout<<"Encoded one "<<result<<endl;
        return result;

    }

    vector<string> decode(string s) {
        cout<<"Decoded input "<<s<<endl;

        vector<string> result;
        int len;
        string cur="";
        int i = 0;
        while(i<s.length())
        {
            int j = i;

            //Read length
            while (s[j] != '#')
            {
                cur += s[j];
                j++;
            }
            len = stoi(cur);

            //Read String
            i = j+1;
            j = i+len;
            cur = s.substr(i,len);
            result.push_back(cur);
            i=j;
            cout<< "Tokens here "<<cur<<endl;
            cur="";
        }
        
        return result;

    }
};
