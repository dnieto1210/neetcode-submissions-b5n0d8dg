class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> posSpeed;
        for(int i = 0; i < position.size(); ++i)
        {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end());

        stack<pair<int,int>> myStack;

        for(int i = posSpeed.size()-1; i >= 0; --i)
        {
            pair<int,int> curr = posSpeed[i];
            if(myStack.empty())
            {
                myStack.push(curr);
            }
            else
            {
                pair<int,int> check = myStack.top();
                double check_speed = static_cast<double>(target - check.first) / check.second;
                double curr_speed = static_cast<double>(target - curr.first) / curr.second;

                if(curr_speed > check_speed)
                {
                    myStack.push(curr);
                }
                else
                {
                    //curr_speed <= check_speed so the car will catch up and become a car fleet
                    //we keep the current car in the stack and we dont add the new one
                }
            }
        }

        return myStack.size();
        
    }
};
