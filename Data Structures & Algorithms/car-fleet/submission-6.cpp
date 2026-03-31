class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 0;
        double tmin = INT_MIN;
        vector<pair<int,int>> cars;
        for(int i=0; i<position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        auto cmp = [](pair<int,int> c1 , pair<int,int> c2) {
            if(c1.first == c2.first) {
                return c1.second > c2.second; 
            }
            return c1.first > c2.first;
        };

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        for (auto car : cars) {
            double time = (double)(target-car.first)/car.second;
            //cout<<"time tmin "<<time<<"  "<<tmin<<endl;
            if(time > tmin) {
                fleet++;
                tmin = time;
            }
        }
        return fleet;
    }
};
