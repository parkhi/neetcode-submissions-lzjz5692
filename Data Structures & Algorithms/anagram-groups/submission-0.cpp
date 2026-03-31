class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;

        for(string str : strs)
        {
            string s=str;
            sort(s.begin(), s.end());
            anagrams[s].push_back(str);
        }

        for( auto itr = anagrams.begin() ; itr != anagrams.end(); itr++)
        {
            result.push_back(itr->second);
        }

        return result;
        
    }
};