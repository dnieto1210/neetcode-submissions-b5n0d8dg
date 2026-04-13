class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        std::vector<std::pair<int,int>> pairs;
        for(int i = 0; i < position.size(); ++i)
        {
            pairs.push_back({position[i], speed[i]});
        }

        std::sort(pairs.rbegin(), pairs.rend());
        std::vector<double> stack;

        for(int i = 0; i < pairs.size(); ++i)
        {
            double t = static_cast<double>((target- pairs[i].first)) / pairs[i].second;
            stack.push_back(t);
            if(stack.size() >= 2 && stack[stack.size()-1] <= stack[stack.size()-2])
            {
                stack.pop_back();
            }
        }
        
        return stack.size();
    }
};
