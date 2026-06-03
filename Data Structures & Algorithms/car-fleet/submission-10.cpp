class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        using Node = pair<int, int>;
        stack<Node> myStack;
        vector<Node> cars(position.size());

        for(int i = 0; i < position.size(); ++i)
        {
            int pos = position[i];
            int spe = speed[i];
            cars[i] = {pos, spe};
        }

        sort(cars.begin(), cars.end()); //sorts in ascending order

        for(int i = cars.size()-1; i >=0 ; --i)
        {
            auto p = cars[i];
            if(myStack.empty())
            {
                myStack.push(p);
            }
            else
            {
                auto ahead = myStack.top();
                double a_res = static_cast<double>(target - ahead.first) / ahead.second;
                double p_res = static_cast<double>(target - p.first) / p.second;
                if(p_res > a_res)
                {
                    myStack.push(p);

                }
                
            }
        }

        return myStack.size();
        
    }
};
