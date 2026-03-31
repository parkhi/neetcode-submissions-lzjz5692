class Solution {
    unordered_map<char,vector<char>> mapping;
    vector<string> res;

    void populate_map() {

        mapping.insert({'1',{}});
        mapping.insert({'2',{'a','b','c'}});
        mapping.insert({'3',{'d','e','f'}});
        mapping.insert({'4',{'g','h','i'}});
        mapping.insert({'5',{'j','k','l'}});
        mapping.insert({'6',{'m','n','o'}});
        mapping.insert({'7',{'p','q','r','s'}});
        mapping.insert({'8',{'t','u','v'}});
        mapping.insert({'9',{'w','x','y','z'}});
    }
public:
    vector<string> letterCombinations(string digits) {          
        string cur;

        if(digits.empty()) {
            return res;
        }
        populate_map();

        place(digits, cur, 0);

        return res;        
    }

    void place(string& digits, string& cur, int i) {
        //cout << "cur is "<<digits.length()<< endl;

        if(i == digits.length()) {
            res.push_back(cur);
            return;
        }
        if(i>digits.length()) {
            return;
        }

        for(char ch: mapping[digits[i]]) {
           // cout << "ch is "<<ch<< endl;
            cur += ch;
            place(digits, cur, i+1);
            cur.pop_back();
        }
    }
};
