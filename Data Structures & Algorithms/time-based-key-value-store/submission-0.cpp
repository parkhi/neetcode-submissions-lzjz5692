class TimeMap {
    unordered_map<string, vector<pair<int , string>>> store;
    string find(string key, int timestamp) {

        string res = "";
        if(!store.count(key)) {
            return res;
        }
        vector<pair<int, string>> val = store[key];
        int l = 0, r = val.size()-1;
        while(l<=r) {
            int m = (l+(r-l)/2);
            cout<<"l r m "<<l<<" "<<r<<" "<<m<<endl;

            if(val[m].first == timestamp) {
                res = val[m].second;
                break;
            }
            else if(val[m].first > timestamp) {
                r = m-1;
            }
            else {
                res = val[m].second;
                l = m+1;                
            }
        }

        return res;
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return find(key, timestamp);
    }
};
