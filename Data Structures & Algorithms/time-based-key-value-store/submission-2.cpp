class TimeMap {
   
public:
    unordered_map<string, vector<pair<int , string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int , string>temp = {timestamp , value};
        store[key].push_back(temp);
    }
    
    string get(string key, int timestamp) {
        
        if(!store.count(key)) {
            return "";
        }

        vector<pair<int, string>>& val = store[key];
        int l = 0, r = val.size()-1;
        string res = "";

        while(l<=r) {
            int m = l+(r-l)/2;

            if(val[m].first <= timestamp) {
                res = val[m].second;
                l = m+1;   
            }
            else{
                r = m-1;
            }
        }

        return res;
    }
};
