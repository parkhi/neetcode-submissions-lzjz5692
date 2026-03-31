
bool sort_frequency (pair<int,int> a, pair<int,int> b)
{
    if (a.second == b.second)
    {
        return (a.first > b.first);
    }
    else
    {
        return (a.second > b.second);
    }
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        vector<int> result;

        //Create frequency map
        for (int num: nums)
        {
            mp[num]++;
        }
        //Lets to the max-heap solution
        priority_queue<pair<int,int>> pq;

        for(auto pair: mp)
        {
            pq.push({pair.second, pair.first});
        }

        for(int i=0; i<k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        /*
        //copy the map into vector for sorting
        vector <pair<int, int>> vmp(mp.begin(), mp.end());

        sort(vmp.begin(), vmp.end(), sort_frequency);

        for(int i=0; i<k; i++)
        {
            result.push_back(vmp[i].first);
        }
        */
        return result;
}

};
