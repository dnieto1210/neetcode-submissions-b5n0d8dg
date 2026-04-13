class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> pairs;
        for(int i = 0; i < position.size(); ++i)
        {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        vector<double> myStack;

        for(int i = 0; i < pairs.size(); ++i)
        {
            pair<int,int> p = pairs[i];
            double time = static_cast<double>(target-p.first) / p.second;
            if(!myStack.empty() && time <= myStack.back())
            {
                continue;
            }

            myStack.push_back(time);
        }

        return myStack.size();
        
    }
};
