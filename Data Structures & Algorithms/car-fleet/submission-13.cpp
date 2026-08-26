class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        stack<double> myStack;
        vector<pair<int,int>> ps;

        for(int i = 0; i < position.size(); ++i)
        {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end());

        for(int i = position.size()-1; i >= 0; --i)
        {
            pair<int,int> p = ps[i];
            int pos = p.first;
            int spe = p.second;

            double res = (target - pos) / static_cast<double>(spe);

            if(!myStack.empty())
            {
                if(myStack.top() >= res)
                {
                    continue;
                }
            }
            myStack.push(res);
        }
        
        return myStack.size();
    }
};
