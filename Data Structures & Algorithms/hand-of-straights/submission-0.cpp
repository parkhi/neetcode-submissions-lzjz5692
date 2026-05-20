class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<>> minhp;

        for(int num: hand) {
            mp[num]++ ;

            if(mp[num] == 1) {
                minhp.push(num);
            }
        }

        while(!minhp.empty()) {
            int cur = minhp.top();

            for(int i=cur; i<cur+groupSize; i++) {
                if(mp.find(i) == mp.end()) {
                    return false;
                }
                mp[i]--;
                if(mp[i] == 0) {
                    if(i != minhp.top()) {
                        return false;
                    }
                    minhp.pop();
                }
            }
        }

        return true;
    }
};
