class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;
        vector<double> times;

        for(int i = 0; i < position.size(); ++i)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        for(int i = 0; i < cars.size(); ++i)
        {
            int p = cars[i].first;
            int s = cars[i].second;
            double t = static_cast<double>(target-p) / s;
            if(!times.empty() && t <= times.back())
            {
                continue;
            }
            times.push_back(t);
        }
        
        return times.size();
    }
};
